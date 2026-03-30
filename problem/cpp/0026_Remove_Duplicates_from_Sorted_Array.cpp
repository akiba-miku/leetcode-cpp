#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, n = nums.size();
        for(int j = 1;j < n; j++){
            if(nums[i-1] == nums[j]) continue;
            nums[i++] = nums[j];
        }
        return i;
    }
};