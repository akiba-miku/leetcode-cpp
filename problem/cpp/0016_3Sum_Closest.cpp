class Solution {
public:
    // 最接近的三数之和， 思路0015 0018差不多
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0;i<n-2;i++){
            for(int l=i+1,r=n-1;l<r;){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==target){
                    return sum;
                }
                else {
                    if(abs(sum-target)<abs(ans-target)){
                        ans = sum;
                    }
                    if(sum>target) --r;
                    else ++l;
                }
            }
        }
        return ans;
    }
};