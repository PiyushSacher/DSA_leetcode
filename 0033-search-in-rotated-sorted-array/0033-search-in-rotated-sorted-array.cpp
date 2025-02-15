class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int high=nums.size()-1;
        while(left<=high){
            int mid=left+(high-left)/2;
            if(nums[mid]==target) return mid;

            //left-sorted
            if(nums[left]<=nums[mid]){
                if(nums[left]<=target && target <=nums[mid]) high=mid-1;
                else left=mid+1;
            }

            //right-sorted
            else{
                if(nums[mid]<=target && target<=nums[high]) left=mid+1;
                else high=mid-1;
            }
        } 
        return -1;       
    }
};