class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;  
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==1){
                count++;
            }
            //nums[i]==0
            else{
                if(count>maxi){
                    maxi=count; 
                    
                }
                count=0;
            }
            if(i==nums.size()-1){
                if(count>maxi){
                    maxi=count;
                }
            }
            
        } 
        return maxi;    
    }
};