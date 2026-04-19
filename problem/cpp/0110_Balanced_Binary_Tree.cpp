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
    int Height(TreeNode *root) {
        return root ? max(Height(root->left), Height(root->right)) + 1
                    : 0;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        return abs(leftHeight - rightHeight) <= 1 && 
            isBalanced(root->left) &&
            isBalanced(root->right);
    }
};