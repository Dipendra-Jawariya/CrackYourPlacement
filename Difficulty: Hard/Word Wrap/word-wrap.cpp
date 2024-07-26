//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    vector<vector<int>> dp;
    int f(int ind,int spaces,int k,vector<int>&nums) {
        // base case
        if(ind == nums.size()) return 0;
        
        if(dp[ind][spaces] != -1) return dp[ind][spaces];
        // continue on the same line
        int newSpaces = spaces + 1 + nums[ind];
        int a = INT_MAX;
        if(newSpaces <= k) {
            a = f(ind+1,newSpaces,k,nums);
        }
        // get on to the next line
        int b = f(ind + 1,nums[ind],k,nums) + (k - spaces)*(k - spaces);
        return dp[ind][spaces] = min(a,b);
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        return f(1,nums[0],k,nums);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends