class Solution {
private:
    int f(int ind1,int ind2,string &s,string &t,vector<vector<int>> &dp) {
        if(ind2 >= t.size()) return 1;
        if(ind1 >= s.size()) return 0;
        
        if(dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        int take = 0;
        int notTake = 0;
        if(s[ind1] == t[ind2]) {
            take += f(ind1+1,ind2+1,s,t,dp);
        }
        notTake += f(ind1+1,ind2,s,t,dp);
        return dp[ind1][ind2] = take + notTake;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        return f(0, 0,s,t,dp);
    }
};