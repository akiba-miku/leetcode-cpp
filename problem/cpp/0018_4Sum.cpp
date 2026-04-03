#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i < n - 3; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j-1] == nums[j]) {
                    continue;
                }
                for(int l = j + 1, r = n; l < r;) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == (long long)target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) --r;
                        l++, --r;
                    }
                    else if(sum > (long long)target) {
                        --r;
                    }
                    else {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};