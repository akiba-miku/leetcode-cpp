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
    // 卡测试
    using ll = signed long long;
    ll preVal = 0x8000000000000000;
    bool isValidBST(TreeNode *root)
    {
        if(root==nullptr) return true;

        auto dfs = [&](this auto &&dfs, TreeNode *root)->bool{
            if(root == nullptr) return true;

            bool isLeftBST = isValidBST(root->left);

            if(!isLeftBST) return false;

            if(preVal >= root->val) return false;

            preVal = root->val

            return isRightBST(root->right);
        }
    }
};