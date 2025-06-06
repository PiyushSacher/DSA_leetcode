class Solution {
public:
vector<vector<int>>dp ;
    bool f(vector<int> &arr,int idx,int k){
        if(k==0) return true;
        if(idx==arr.size()) return false;
        if(dp[idx][k]!=-1) return dp[idx][k];
        if(arr[idx]<=k){//can include
            return dp[idx][k]=f(arr,idx+1,k-arr[idx]) || f(arr,idx+1,k);
        }
        //exclude
        return dp[idx][k]=f(arr,idx+1,k);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<=nums.size()-1;i++) sum=sum+nums[i];
        if(sum%2!=0) return false;
        dp.clear();
        dp.resize(200,vector<int>(20005,-1));
        return f(nums,0,sum/2);
        
    }
};