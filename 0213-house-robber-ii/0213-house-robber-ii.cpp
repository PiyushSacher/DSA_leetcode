class Solution {
public:
    int f(vector<int> &nums,int idx,vector<int> &dp){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int pick=nums[idx]+f(nums,idx-2,dp);
        int notPick=0+f(nums,idx-1,dp);
        
        return dp[idx]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);

        vector<int>first;
        vector<int>second;

        if(nums.size()==1) return nums[0];
        
        for(int i=0;i<n;i++){
            if(i!=0) first.push_back(nums[i]);
            if(i!=n-1) second.push_back(nums[i]);
        }

        return max(f(first,first.size()-1,dp1),f(second,second.size()-1,dp2));
        
    }
};