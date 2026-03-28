#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size()-1;
        int ans = 0;
        int sum = 0;
        while(l<r){
            sum = people[l] + people[r];
            if(sum > limit) {
                r--; // 那么r要单独一艘船
            }
            else {
                l++ ,--r;
            }
            ans++;
        }
        // l==r,最后只剩下一个人单独上船·
        if(l == r) ans++;
        return ans;
    }
};