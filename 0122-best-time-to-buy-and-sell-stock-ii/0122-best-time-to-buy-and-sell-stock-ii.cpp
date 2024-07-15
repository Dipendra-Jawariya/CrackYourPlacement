class Solution {
private:
    int f(int ind,int buy,int n,vector<int> &prices,vector<vector<int>> &dp) {
        if(ind == n) {
            return 0;
        }
        
        if(dp[ind][buy] != -1)  return dp[ind][buy];
        
        int profit = INT_MIN;
        if(buy) {
            profit = max((-1*prices[ind] + f(ind+1,0,n,prices,dp)),
                        (0 + f(ind+1,1,n,prices,dp))); 
        } else {
            profit = max(prices[ind] + f(ind+1,1,n,prices,dp),
                        0+ f(ind+1,0,n,prices,dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,n,prices,dp);
    }
};