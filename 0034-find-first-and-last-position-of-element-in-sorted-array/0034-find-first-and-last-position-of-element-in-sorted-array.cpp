class Solution {
public:
    vector<int>result;
    int firstOcc(vector<int> &nums,int target){
        int ans=-1;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return ans;    
    }

    int LastOcc(vector<int> &nums,int target){
        int ans=-1;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return ans;    
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOcc(nums,target);
        result.push_back(first);
        //as if there is not firstOccurence how can there be a lastOcuurence
        if(first==-1) return {-1,-1};
        
        result.push_back(LastOcc(nums,target));   

        return result;   

    }
};