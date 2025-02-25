class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing=arr[mid]-(mid+1);

            if(missing<k) low=mid+1;
            else high=mid-1;
        }
        //now high and low are crossing each other and are pointing to the search space where k can be found
        return k+high+1;
        
    }
};