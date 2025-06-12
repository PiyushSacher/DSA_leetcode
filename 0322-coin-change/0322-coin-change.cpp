class Solution {
public:
    int f(int idx,int target,vector<int> &coins, vector<vector<int>> &dp){
        if(idx==0){
            if(target%coins[0]==0) return target/coins[0];
            else return 1e9;
        }

        if(dp[idx][target]!=-1) return dp[idx][target];

        int notPick=0+f(idx-1,target,coins,dp);
        int pick=INT_MAX;
        if(coins[idx]<=target){
            pick=1+f(idx,target-coins[idx],coins,dp);
        }
        return dp[idx][target]=min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int res=f(n-1,amount,coins,dp);
        return res==1e9? -1: res;
    }
};