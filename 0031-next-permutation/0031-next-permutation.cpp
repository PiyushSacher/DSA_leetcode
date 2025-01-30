class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivotIdx=-1;
        //finding pivot element
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]) {
                pivotIdx=i;
                break;
            }
        }
        if(pivotIdx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=nums.size()-1;i>pivotIdx;i--){
            if(nums[i]>nums[pivotIdx]){
                swap(nums[i],nums[pivotIdx]);
                break;
            }
        }

        reverse(nums.begin()+pivotIdx+1,nums.end());

    }        
};