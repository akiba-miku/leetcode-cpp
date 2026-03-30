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
class Solution
{
public:
    // 很重要
    int maxPathSum(TreeNode *root)
    {
        int ans = 0x80000000;
        auto dfs = [&](this auto &&dfs, TreeNode *root)->decltype(auto){
            if(root == nullptr) return 0;

            int leftMaxPath = max(0, dfs(root->left));
            int rightMaxPath = max(0, dfs(root->right));
            
            ans = max(ans, leftMaxPath + rightMaxPath + root->val);

            return root->val + max(leftMaxPath, rightMaxPath); 
        };
        dfs(root);
        return ans; 
    }
};