#include <cassert>
#include <functional>
#include <iostream>
#include <string>

// ─────────────────────────────────────────────
// 层次一：节点
// ─────────────────────────────────────────────
enum class Color { RED, BLACK };

template <typename K, typename V>
struct RBNode {
    K key;
    V val;
    Color color;
    RBNode *parent, *left, *right;

    RBNode(K k, V v, Color c, RBNode* nil)
        : key(k), val(v), color(c), parent(nil), left(nil), right(nil) {}
};

// ─────────────────────────────────────────────
// 层次二：红黑树
// ─────────────────────────────────────────────
template <typename K, typename V>
class RBTree {
public:
    using Node = RBNode<K, V>;

    RBTree() {
        // 哨兵节点：统一代替所有 NIL，简化边界判断
        nil_ = new Node(K{}, V{}, Color::BLACK, nullptr);
        nil_->parent = nil_->left = nil_->right = nil_;
        root_ = nil_;
    }

    ~RBTree() { clear(root_); delete nil_; }

    // ── 公开接口 ──────────────────────────────

    void insert(K key, V val) {
        Node* z = new Node(key, val, Color::RED, nil_);
        bstInsert(z);
        insertFixup(z);
    }

    bool erase(K key) {
        Node* z = search(root_, key);
        if (z == nil_) return false;
        rbDelete(z);
        return true;
    }

    V* find(K key) {
        Node* n = search(root_, key);
        return n == nil_ ? nullptr : &n->val;
    }

    // 中序遍历（升序）
    void inorder(std::function<void(K, V)> fn) const {
        inorder(root_, fn);
    }

    int blackHeight() const { return blackHeight(root_); }

private:
    Node* root_;
    Node* nil_;   // 哨兵

    // ─────────────────────────────────────────
    // 层次三：旋转（不改变 BST 性质，只调整结构）
    // ─────────────────────────────────────────

    //        x                  y
    //       / \      L←        / \
    //      α   y     →R       x   γ
    //         / \            / \
    //        β   γ          α   β

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nil_) y->left->parent = x;

        y->parent = x->parent;
        if (x->parent == nil_)       root_ = y;
        else if (x == x->parent->left) x->parent->left  = y;
        else                           x->parent->right = y;

        y->left  = x;
        x->parent = y;
    }

    void rotateRight(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nil_) x->right->parent = y;

        x->parent = y->parent;
        if (y->parent == nil_)       root_ = x;
        else if (y == y->parent->left) y->parent->left  = x;
        else                           y->parent->right = x;

        x->right  = y;
        y->parent = x;
    }

    // ─────────────────────────────────────────
    // 层次四：BST 基础插入 + RB 修复
    // ─────────────────────────────────────────

    void bstInsert(Node* z) {
        Node* y = nil_;
        Node* x = root_;
        while (x != nil_) {
            y = x;
            x = (z->key < x->key) ? x->left : x->right;
        }
        z->parent = y;
        if      (y == nil_)       root_    = z;
        else if (z->key < y->key) y->left  = z;
        else                      y->right = z;
    }

    // 插入修复：处理"双红"冲突（违反性质 4）
    //
    // 共三种情形（以 z 在祖父左子树为例，右子树对称）：
    //
    //  Case 1：叔父红 → 重新着色，问题上移
    //  Case 2：叔父黑，z 是右孩子 → 旋转变为 Case 3
    //  Case 3：叔父黑，z 是左孩子 → 旋转 + 重新着色
    void insertFixup(Node* z) {
        while (z->parent->color == Color::RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;   // 叔父
                if (y->color == Color::RED) {          // Case 1
                    z->parent->color          = Color::BLACK;
                    y->color                  = Color::BLACK;
                    z->parent->parent->color  = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {       // Case 2 → Case 3
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color         = Color::BLACK;  // Case 3
                    z->parent->parent->color = Color::RED;
                    rotateRight(z->parent->parent);
                }
            } else {                                   // 镜像
                Node* y = z->parent->parent->left;
                if (y->color == Color::RED) {
                    z->parent->color          = Color::BLACK;
                    y->color                  = Color::BLACK;
                    z->parent->parent->color  = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color         = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root_->color = Color::BLACK;  // 性质 2
    }

    // ─────────────────────────────────────────
    // 层次四：删除 + RB 修复
    // ─────────────────────────────────────────

    // 用子树 v 替换子树 u 的位置
    void transplant(Node* u, Node* v) {
        if      (u->parent == nil_)     root_          = v;
        else if (u == u->parent->left)  u->parent->left  = v;
        else                            u->parent->right = v;
        v->parent = u->parent;
    }

    Node* minimum(Node* x) {
        while (x->left != nil_) x = x->left;
        return x;
    }

    void rbDelete(Node* z) {
        Node* y = z;
        Node* x;
        Color yOrigColor = y->color;

        if (z->left == nil_) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nil_) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);      // 后继
            yOrigColor = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (yOrigColor == Color::BLACK)
            deleteFixup(x);             // 黑色节点被移走，需修复
    }

    // 删除修复：处理"双黑"（违反性质 5）
    //
    //  Case 1：兄弟红 → 旋转，转化为 Case 2/3/4
    //  Case 2：兄弟黑，兄弟子全黑 → 上移
    //  Case 3：兄弟黑，近侄红远侄黑 → 旋转，转化为 Case 4
    //  Case 4：兄弟黑，远侄红 → 旋转 + 重新着色，结束
    void deleteFixup(Node* x) {
        while (x != root_ && x->color == Color::BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == Color::RED) {           // Case 1
                    w->color          = Color::BLACK;
                    x->parent->color  = Color::RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color  == Color::BLACK &&
                    w->right->color == Color::BLACK) {  // Case 2
                    w->color = Color::RED;
                    x = x->parent;
                } else {
                    if (w->right->color == Color::BLACK) {  // Case 3
                        w->left->color = Color::BLACK;
                        w->color       = Color::RED;
                        rotateRight(w);
                        w = x->parent->right;
                    }
                    w->color          = x->parent->color;   // Case 4
                    x->parent->color  = Color::BLACK;
                    w->right->color   = Color::BLACK;
                    rotateLeft(x->parent);
                    x = root_;
                }
            } else {                                    // 镜像
                Node* w = x->parent->left;
                if (w->color == Color::RED) {
                    w->color          = Color::BLACK;
                    x->parent->color  = Color::RED;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == Color::BLACK &&
                    w->left->color  == Color::BLACK) {
                    w->color = Color::RED;
                    x = x->parent;
                } else {
                    if (w->left->color == Color::BLACK) {
                        w->right->color = Color::BLACK;
                        w->color        = Color::RED;
                        rotateLeft(w);
                        w = x->parent->left;
                    }
                    w->color          = x->parent->color;
                    x->parent->color  = Color::BLACK;
                    w->left->color    = Color::BLACK;
                    rotateRight(x->parent);
                    x = root_;
                }
            }
        }
        x->color = Color::BLACK;
    }

    // ─────────────────────────────────────────
    // 辅助函数
    // ─────────────────────────────────────────

    Node* search(Node* x, K key) const {
        while (x != nil_) {
            if      (key == x->key) return x;
            else if (key <  x->key) x = x->left;
            else                    x = x->right;
        }
        return nil_;
    }

    void inorder(Node* x, std::function<void(K, V)>& fn) const {
        if (x == nil_) return;
        inorder(x->left, fn);
        fn(x->key, x->val);
        inorder(x->right, fn);
    }

    int blackHeight(Node* x) const {
        if (x == nil_) return 0;
        int lh = blackHeight(x->left);
        return lh + (x->color == Color::BLACK ? 1 : 0);
    }

    void clear(Node* x) {
        if (x == nil_) return;
        clear(x->left);
        clear(x->right);
        delete x;
    }
};

// ─────────────────────────────────────────────
// 测试
// ─────────────────────────────────────────────
int main() {
    RBTree<int, std::string> t;

    // 插入
    for (int k : {10, 20, 30, 15, 5, 1, 25}) {
        t.insert(k, "v" + std::to_string(k));
    }

    // 中序应升序输出
    std::cout << "inorder: ";
    t.inorder([](int k, std::string v) {
        std::cout << k << " ";
    });
    std::cout << "\n";

    // 查找
    auto* p = t.find(15);
    assert(p && *p == "v15");
    assert(t.find(99) == nullptr);

    // 删除
    assert(t.erase(15));
    assert(t.find(15) == nullptr);

    // 黑高应 > 0
    assert(t.blackHeight() > 0);

    std::cout << "all tests passed\n";
    return 0;
}
