class Solution {
public:
    int ma(vector<int>&nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i],maxi);
        }
        return maxi;
    }
    int sumD(vector<int>&nums,int d){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)(nums[i]/double(d)));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {  
        int low=1;
        int high=ma(nums);
        int ans=high;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(sumD(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};