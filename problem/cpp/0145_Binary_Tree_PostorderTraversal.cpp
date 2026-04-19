#include <algorithm>
#include <vector>
#include <stack>
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
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return ans;
        stack<TreeNode*> st;
        st.push(root);
        // 左 右 根
        // 根 右 左
        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->left) {
                st.push(node->left);
            }
            if(node->right) {
                st.push(node->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};