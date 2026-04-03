#include <algorithm>
#include <queue>
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
    int maxDepth1(TreeNode *root)
    {
        return root != nullptr ? max({maxDepth1(root->left), maxDepth1(root->right)}) + 1
                    : 0;
    }

    int maxDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        int depth = 0;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto node = q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            depth++;
        }

        return depth;
    }

};