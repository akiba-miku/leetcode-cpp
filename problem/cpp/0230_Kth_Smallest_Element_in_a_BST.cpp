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
    int kthSmallest(TreeNode *root, int k)
    {
        int cnt = 0, ans = -1;
        auto dfs = [&](this auto&& dfs,TreeNode *root, int k){
            if(!root || ans != -1) return ;
            dfs(root->left, k);
            if(++cnt == k) {
                ans = root->val;
                return ;
            }
            dfs(root->right, k);
        };
        dfs(root, k);
        return ans;
    }
};