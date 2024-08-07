//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void dfs(int row,int col,vector<vector<char>> &mat,vector<vector<int>>&vis) {
        vis[row][col] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            mat[nrow][ncol] == 'O' && vis[nrow][ncol] == 0) {
                dfs(nrow,ncol,mat,vis);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int j = 0; j < m; j++) {
            if(vis[0][j] == 0 && mat[0][j] == 'O')  {
                dfs(0,j,mat,vis);
            }
            if(vis[n-1][j] == 0 && mat[n-1][j] == 'O') {
                dfs(n-1,j,mat,vis);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(vis[i][0] == 0 && mat[i][0] == 'O') {
                dfs(i,0,mat,vis);
            }
            if(vis[i][m-1] == 0 && mat[i][m-1] == 'O') {
                dfs(i,m-1,mat,vis);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && mat[i][j] =='O') {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends