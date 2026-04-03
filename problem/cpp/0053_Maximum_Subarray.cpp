#include <vector>
using namespace std;

class Solution {
public:
    // 滚动数组的方案自己想
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        int max_val = nums[0];
        for(int i=1;i<n;++i){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            max_val = max(max_val, dp[i]);
        }
        return max_val;
    }
};