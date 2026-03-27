#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n;
        while(l<r) {
            // l -> l + 1
            if(nums[l] == l+1) ++l;
            else if(nums[l] <= l) swap(nums[l], nums[--r]);
            else if(nums[l] > r) swap(nums[l], nums[--r]);
            else if(nums[nums[l]-1] == nums[l]) swap(nums[l], nums[--r]);
            else swap(nums[l], nums[nums[l]-1]);
        }
        return l+1;// r+1
    }
};