class Solution {
public:
    int findMin(vector<int>& nums) {
        //the sorted part of the rotated sorted array may have the answer or may not have the answer

        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;
            //identify the sorted half

            //left-sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<ans){
                    ans=nums[low];
                }
            low=mid+1;
            }
            //right-sorted
            else{
                if(nums[mid]<ans){
                    ans=nums[mid];
                    high=mid-1;
                }
            }

        }
        return ans;
        
    }
};