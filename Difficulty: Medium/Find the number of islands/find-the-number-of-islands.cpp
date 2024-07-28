//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>> &vis,
    vector<vector<char>> &grid) {
        vis[row][col] = 1;
        
        int delRow[8] = {-1,-1,0,1,1,1,0,-1};
        int delCol[8] = {0,1,1,1,0,-1,-1,-1};
        
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < 8; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            vis[nrow][ncol] == 0  && grid[nrow][ncol] == '1')  {
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int islands = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && grid[i][j] == '1') {
                    dfs(i,j,vis,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends