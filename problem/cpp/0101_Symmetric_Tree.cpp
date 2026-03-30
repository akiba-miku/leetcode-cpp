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
#include <queue>
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
// 基本递归， 层序遍历， dfs+stack
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        auto dfs = [&](this auto &&dfs, TreeNode *left, TreeNode *right)->bool{
            if(left == nullptr && right == nullptr) return true;
            if(left == nullptr || right == nullptr) return false;
            if(left->val != right->val) return false;

            // left->val == right->val
            return dfs(left->left, right->right) 
                && dfs(left->right, right->left);
        };

        return dfs(root->left, root->right);
    }
};