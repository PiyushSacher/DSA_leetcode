class Solution {
public:
    int maxEle(vector<int>&piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }

    long long func(vector<int>&piles,int mid){
        long long total=0;
        for(int i=0;i<piles.size();i++){
            total+=(piles[i]+mid-1)/mid;            
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1;
        long long high=maxEle(piles);
        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;

            long long totalHrs=func(piles,mid);
            if(totalHrs<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }   
        return (int)ans;  
    }
};