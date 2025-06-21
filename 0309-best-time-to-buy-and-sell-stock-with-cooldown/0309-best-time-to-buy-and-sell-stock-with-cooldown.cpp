class Solution {
public:
    int f(int idx,int buy,vector<vector<int>>&dp,vector<int>&prices){
        if(idx>=prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];

        int profit=0;
        if(buy){
            profit=max(-prices[idx]+f(idx+1,0,dp,prices),0+f(idx+1,1,dp,prices));
        }
        else{
            profit=max(prices[idx]+f(idx+2,1,dp,prices),0+f(idx+1,0,dp,prices));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return f(0,1,dp,prices);
    }
};