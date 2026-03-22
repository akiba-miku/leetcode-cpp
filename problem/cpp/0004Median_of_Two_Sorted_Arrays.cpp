class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // ensure m is greater than n
        if(nums1.size() < nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int l = 0, r = m;
        while(l<=r){
            int i = (l+r)>>1;
            int j = (m+n+1)/2-i;

            int a1 = i==0?0x80000000:nums1[i-1];
            int a2 = i==m?0x7fffffff:nums1[i];
            int b1 = j==0?0x80000000:nums2[j-1];
            int b2 = j==n?0x7fffffff:nums2[j];
            
            if(a1<=b2&&b1<=a2){
                if((m+n)%2==0) {
                    return static_cast<double>(max(a1,b1)+min(a2,b2))/2.0;
                }
                else {
                    return static_cast<double>(max(a1,b1));
                }
            }
            else if(a1>b2) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }

        }
        return 0.0;
    }
};