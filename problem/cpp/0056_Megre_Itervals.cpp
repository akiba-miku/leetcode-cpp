#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const auto &a, const auto &b){
                if(a[0]!=b[0]) {
                    return a[0] < b[0];
                }
                return a[1] < b[1];
            });
        vector<vector<int>> ans;
        for(auto &p : intervals) {
            if(ans.empty() || p[0] > ans.back()[1]) {
                ans.push_back(p);
            } else {
                ans.back()[1] = max(p[1], ans.back()[1]);
            }
        }
        return ans;
    }
};