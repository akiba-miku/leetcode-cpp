#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 以当前节点为根节点的最小路径
    // 递归写法， 讨论节点为 nullptr, 内部节点， 叶子节点的情况。
    int dfs(TreeNode *root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        if(root->left == nullptr) {
            return dfs(root->right) + 1;
        }
        if(root->right == nullptr) {
            return dfs(root->left) + 1;
        }
        return min(dfs(root->left), dfs(root->right)) + 1;
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};