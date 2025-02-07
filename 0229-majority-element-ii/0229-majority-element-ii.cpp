class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int el1=INT_MIN;
        int el2=INT_MIN;

        int cnt1=0,cnt2=0;

        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }

            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        int check1=0;
        int check2=0;
        for(int i=0;i<nums.size();i++){
            if(el1==nums[i]) check1++;
            if(el2==nums[i]) check2++;
        }
        if(check1>(nums.size())/3) v.push_back(el1);
        if(check2>(nums.size())/3) v.push_back(el2);

        return v;
    }
};
