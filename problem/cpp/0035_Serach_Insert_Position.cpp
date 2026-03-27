#include <vector>
using namespace std;

class Solution {
public:
    // 面试热门模版
    // lower_bound >= target 的第一个数 => 这道题等价于这个
    // upper_bound > target 的第一个数
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = n; // 默认尾部插入
        while(l <= r) {
            int m = l + ((r - l) >> 1); //取中点，向下取整
            if(nums[m] >= target) {
                ans = m;    // 正确的但不是最边界的
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};