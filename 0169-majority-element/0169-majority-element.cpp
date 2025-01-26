class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int el;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt++;
                el=nums[i];
            }
            else if(nums[i]==el) cnt++;
            else cnt--;
        }

        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el){
                temp++;
            }
        }
        if(temp>nums.size()/2) {
            return el;
        } 
        return el;    

    }
};