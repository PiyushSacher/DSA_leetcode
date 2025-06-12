class Solution {
public:

int f(int idx,int tar,vector<int>&arr,vector<vector<int>>&dp){
	if (idx==0) {
        if(tar== 0 && arr[0]==0) return 2;  
		if(tar==0 || arr[0]==tar) return 1;          
        return 0;
    }

	if(dp[idx][tar]!=-1) return dp[idx][tar];
	int notPick=f(idx-1,tar,arr,dp);
	int pick=0;
	if(arr[idx]<=tar) pick=f(idx-1,tar-arr[idx],arr,dp);
	return dp[idx][tar]=(pick+notPick);
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
	return f(n-1,k,arr,dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum=0;
    for(int i=0;i<arr.size();i++) totalSum+=arr[i];
    if(totalSum-d<0 || (totalSum-d)%2!=0) return false;
    return findWays(arr,(totalSum-d)/2);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    return countPartitions(n,target,nums);
        
}
};