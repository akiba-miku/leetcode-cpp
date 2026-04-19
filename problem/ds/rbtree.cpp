

enum class Color { RED, BLACK };

template <typename K, typename V>
struct RBNode {
    K key;
    V val;
    Color color;
    RBNode *p, *l, *r;

    RBNode(K k, V v, Color c, RBNode *nil)
        : key(k), val(val), color(c), p(nil), l(nil), r(nil) {}
};

template <typename K, typename V>
class RBTree {
public:
    using Node = RBNode<K, V>;

    RBTree() {
        nil_ = new Node(K{}, V{}, Color::BLACK, nullptr);
        nil_->p = nil_->l = nil_->r = nil_;
        root_ = nil_;
    }

    ~RBTree() { clear(root_); delete nil_;}

    void Insert(K key, V val) {
        Node *z = new Node(key, val, Color::BLACK, nil_);
        bstInsert(z);
        insertFixup(z);
    }
private:
    void bstInsert(Node *z) {
        Node *y = nil_;
        Node *x = root_;
        while (x != nil_) {
            y = x;
            x = (z->key < x->key) ? x->left : x->right;
        }
        z->p = y;
        if (y == nil_) root_ = z;
        else if (z->key < y->key) y->l = z;
        else y->r = z;
    }
private:
    Node *root_;
    Node *nil_;
};