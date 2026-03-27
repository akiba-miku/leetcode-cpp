#include <vector>
using namespace std;
class Solution {
public:
    int trap1(vector<int>& height) {
        // ans_at(i), min (leftMax[i-1], rightMax[i+1]) compare with 0.
        int n = height.size();
        if(n <= 2) return -1;
        
        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = height[0]; 
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];
        for(int i= n-2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int ans = 0;
        for(int i=1;i<n-1;i++) {
            ans += max(0, min(leftMax[i-1], rightMax[i+1])-height[i]);
        }
        return ans;
    }

    int trap(vector<int> &height) {
        int n = height.size();
        if(n <= 2) return -1;
        int l=1, r=n-2, lmax=height[0], rmax=height[n-1];
        int ans = 0;
        while(l<=r) {
            if(lmax <= rmax) {
                ans += max(0, lmax - height[l]);
                lmax = max(lmax, height[l++]);
            }
            else {
                ans += max(0, rmax - height[r]);
                rmax = max(rmax, height[r--]);
            }
        }
        return ans;
    }
};