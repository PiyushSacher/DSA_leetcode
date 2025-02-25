class Solution {
public:
    int ma(vector<int>&weights){
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
        }
        return maxi;
    }

    int sum(vector<int>&weights){
        int s=0;
        for(int i=0;i<weights.size();i++) s+=weights[i];
        return s;
    }
    
    int fun(vector<int>&weights,int cap){
        int days=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                days=days+1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low=ma(weights);
        int high=sum(weights);
        int ans=high;

        while(low<=high){
            int mid=low+(high-low)/2;
            
            int daysReq=fun(weights,mid);
            if(daysReq<=days){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
            
        }
        return ans;
    }
};