class Solution {
public:
    bool f(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0) return true;
        if(i==0) return (nums[0]==target);

        if(dp[i][target]!=-1) return dp[i][target];

        bool notPick=f(i-1,target,nums,dp);
        bool pick=false;
        if(target>=nums[i]){
            pick=f(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target]=pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2!=0) return false;
        else {
            int n=nums.size();
            vector<vector<int>>dp(n+1,vector<int>(20001,-1));
            return f(nums.size()-1,sum/2,nums,dp);
        }        
    }
};