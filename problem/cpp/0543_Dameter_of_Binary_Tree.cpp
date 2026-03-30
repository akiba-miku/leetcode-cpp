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
class Solution {
public:
    // 全局变量代替树形dp的做法
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        auto dfs = [&maxDiameter](this auto &&dfs, TreeNode *root){
            if(root == nullptr) return 0;

            int leftHeight = dfs(root->left);
            int rightHeight = dfs(root->right);

            maxDiameter = max(maxDiameter, leftHeight + rightHeight);

            return max(leftHeight, rightHeight) + 1;
        };
        dfs(root);
        return maxDiameter;
    }
};