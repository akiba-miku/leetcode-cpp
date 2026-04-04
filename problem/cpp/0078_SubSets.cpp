#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();        
        vector<int> path;
        auto dfs = [&](this auto &&dfs, int i)->void{
            if (i == n) {
                ans.push_back(path);
                return;
            }
            dfs(i+1);
            path.push_back(nums[i]);
            dfs(i+1);
            path.pop_back();
        };
        dfs(0);
        return ans;
    }
};