#include <vector>

using namespace std;

class Solution {
public:
    // dfs解法和并查集解法
    int numIslands1(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        auto dfs = [&](this auto &&dfs, int i,int j){
            if(i<0||i>=m||j<0||j>=n||grid[i][j]=='0') return ;
            
            grid[i][j] = '0';
            dfs(i+1,j);
            dfs(i,j+1);
            dfs(i-1,j);
            dfs(i,j-1);
        };

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ++ans;
                    dfs(i,j);
                }
            }
        }
        return ans;
    }
struct DSU {
    vector<int> fa, sz;

    DSU(int n) : fa(n+1), sz(n+1,1){
        for(int i=1;i<=n;i++){
            fa[i] = i;
        }
    }

    int find(int x){
        return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
    }

    bool unite(int x,int y) {
        int fx = find(x), fy = find(y);
        if(fx == fy) return false;
        if(sz[fx] < sz[fy]) swap(fx, fy);
        fa[fy] = fx;
        sz[fx] += sz[fy];
        return true;
    }

} ;
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        Dsu dsu(m * n);
        auto id = [&](int i,int j){
            return i * n + j;
        };
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1') cnt++;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0')
                    continue;
                
                if(i+1<m&&grid[i+1][j]=='1'){
                    if(dsu.unite(id(i,j),id(i+1,j))) --cnt;
                }
                if(j+1<n&&grid[i][j+1]=='1'){
                    if(dsu.unite(id(i,j), id(i,j+1))) --cnt;
                }
            }
        }

        return cnt;
    }
};