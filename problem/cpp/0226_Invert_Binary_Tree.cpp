/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if(!root) return nullptr;
        auto dfs = [&](this auto &&dfs, TreeNode *node)->decltype(auto) {
            if(!node) return nullptr;

            // 后序遍历
            TreeNode *left = dfs(node->left);
            TreeNode *right = dfs(node->right);
            node->left = right;
            node->right = left;
            return node;
        };
        return dfs(root);
    }
};