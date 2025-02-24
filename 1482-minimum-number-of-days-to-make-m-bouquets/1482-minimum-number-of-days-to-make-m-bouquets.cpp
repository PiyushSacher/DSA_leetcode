class Solution {
public:
    int mi(vector<int>&bloomDay){
        int mini=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(mini,bloomDay[i]);
        }
        return mini;
    }

    int ma(vector<int>&bloomDay){
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi=max(maxi,bloomDay[i]);
        }
        return maxi;
    }

    bool possible(vector<int>&bloomDay,int day,int m,int k){
        int cnt=0;
        int bouq=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day) cnt++;
            else{
                bouq+=cnt/k;
                cnt=0;
            }       
        }
        bouq+=cnt/k;
        if(bouq>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size();
        long long mul=m*1LL *k* 1LL;
        if(mul>n) return -1;

        int mini=mi(bloomDay);
        int maxi=ma(bloomDay);

        int low=mini;
        int high=maxi;
        int ans=high;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)==true){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;    
    }
};