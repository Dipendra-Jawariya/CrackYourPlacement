//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void permutation(vector<int> &arr,set<vector<int>> &ans, 
    vector<int> &isVis,vector<int> &ds) {
        if(ds.size() == arr.size()) {
            ans.insert(ds);
            return;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(!isVis[i]) {
                isVis[i] = 1;
                ds.push_back(arr[i]);
                permutation(arr,ans,isVis,ds);
                isVis[i] = 0;
                ds.pop_back();
            }
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> st;
        vector<int> isVis(n,0);
        vector<int> ds;
        permutation(arr,st,isVis,ds);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends