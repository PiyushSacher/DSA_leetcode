class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            //mid is at the peak element
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;

            //mid is at the increasing curve,so the peak element must be ahead
            else if(nums[mid]>nums[mid-1] && nums[mid] <nums[mid+1]) low=mid+1;

            //mid is at the decreasing curve,so the peak element must be before
            else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]) high=mid-1;

            else low=mid+1;
            //or we can write high=mid-1 , as this case is written if we have multiple peak elements and mid is at the dip,so peak could be found either before or after as we can return any peak element
        }    
        return -1;   
    }
};