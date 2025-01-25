class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            int more=target-curr;
            if(mp.find(more)!=mp.end()){
                //exists 
                v.push_back(mp[more]);
                v.push_back(i);
                return v;                               
            }
            mp[nums[i]]=i;
        }
        return v;       
    }
};