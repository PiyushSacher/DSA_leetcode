class Solution {
public:
   int ma(vector<int>&nums){
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);
    }
    return maxi;
   }

   int sum(vector<int>&nums){
    int s=0;
    for(int i=0;i<nums.size();i++){
        s+=nums[i];
    }
    return s;
   }

   int fun(vector<int> &nums, int sum){
    int painters=1;
    long long s=0;
    for(int i=0;i<nums.size();i++){
        if(s+nums[i]<=sum){
            s+=nums[i];
        }
        else{
            painters+=1;
            s=nums[i];
        }
    }
    return painters;
   }

    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int low=ma(nums);
        int high=sum(nums);
        int ans=high;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int noOfPainters=fun(nums,mid);
            if(noOfPainters==k){
                ans=mid;
                high=mid-1;
            }
            else if(fun(nums,mid)>k){
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;


    }
};