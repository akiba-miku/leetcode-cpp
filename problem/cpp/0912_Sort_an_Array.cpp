#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
class Solution {
public:
    // https://leetcode.cn/problems/sort-an-array/
    // 快速排序

    // 🇳🇱三色国旗法
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l,int r) {
        if(l > r) return ;
        int p = nums[l + rand() % (r - l + 1)];
        int lt=l,gt=r;
        for(int i=l;i<=gt;) {
            if(nums[i] < p) swap(nums[i++], nums[lt++]);
            else if(nums[i] > p) swap(nums[i], nums[gt--]);
            else i++;
        }
        quickSort(nums, l, lt-1);
        quickSort(nums, gt+1, r);
    }

    vector<int> help;
    vector<int> sortArray1(vector<int>& nums) {
        help = vector<int>(nums.size());
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l,int r) {
        if(l >= r) return;
        int m = l + ((r - l) >> 1);
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);

        int i=l,j=m+1,k=l;
        while(i<=m&&j<=r){
            help[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        while(i<=m) help[k++] = nums[i++];
        while(j<=r) help[k++] = nums[j++];
        for(i=l;i<=r;i++) nums[i] = help[i];
    }
};