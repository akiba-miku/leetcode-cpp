#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(128, -1); // char -> last index
        int n = s.size();
        int ans = 0;
        for(int l=0,r=0;r<n; r++) {
            if(mp[s[r]]>=l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};