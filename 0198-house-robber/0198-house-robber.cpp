class Solution {
    vector<int> dp;
public:
    int f(int idx,vector<int> &arr){
        if(idx>=arr.size()){
            return 0;
        }
        if(dp[idx]==-1){
            dp[idx]=max(arr[idx]+f(idx+2,arr),0+f(idx+1,arr));
            return dp[idx];
        }
        return dp[idx];
    }

    int rob(vector<int>& nums) {
        dp.resize(nums.size()+10,-1);
        return f(0,nums);        
    }
};