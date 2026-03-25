class Solution {
public:
    // https://leetcode.cn/problems/sort-an-array/
    // 快速排序
    vector<int> sortArray(vector<int>& nums) {
        auto quick_sort = [&](this auto&& quick_sort, int l,int r)->void{
            if(l>=r) return ;

            int pivot = nums[l+rand()%(r-l+1)];

            int lt=l,i=l,gt=r;
            // [l, lt-1], [lt, gt],[gt+1, r]
            while(i<=gt){
                if(nums[i]<pivot) swap(nums[i++],nums[lt++]);
                else if(nums[i]>pivot) swap(nums[i],nums[gt--]);
                else i++;
            }

            quick_sort(l,lt-1);
            quick_sort(gt+1,r);
        };
        quick_sort(0,nums.size()-1);
        return nums;
    }
};