class Solution {
public:
    // (r-l)*max(height[l], height[r]) 总结公式
    int maxArea(vector<int>& height) {
        int cap = 0;
        int l = 0, r = height.size();
        while(l<r){
            int h = min(height[l], height[r]);
            int ans = max(ans, (r-l)*h);
            if(height[l]<height[r]) ++l;
            else --r;
        }
        return ans;
    }
};