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

#include <vector>
using namespace std;
;
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        auto dfs = [&](this auto &&dfs, int i, int j) -> TreeNode*
        {
            if (i > j)
                return nullptr;
            if (i == j)
                return new TreeNode(nums[i], nullptr, nullptr);
            int m = i + ((j - i) >> 1);
            TreeNode *node = new TreeNode(nums[m]);
            node->left = dfs(i, m - 1);
            node->right = dfs(m + 1, j);
            return node;
        };
        return dfs(0, nums.size()-1);
    }
};