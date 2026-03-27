#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int l=i+1,r=n-1;l<r;){
                int sum = nums[l] + nums[r] + nums[i];
                if(sum == 0) {
                    ans.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
                    while(l<r&&nums[l]==nums[l+1]) l++;
                    while(l<r&&nums[r]==nums[r-1]) r--;
                    l++, r--;
                }
                else if(sum > 0) r--;
                else l++;
            }
        }
        return ans;
    }
};