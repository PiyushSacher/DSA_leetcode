class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int maxlen=0;
        map<int,int>mpp;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                while(mpp.size()>2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                    l++;
                } 
            }

            if(mpp.size()<=2){
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            //r++;
        }
        return maxlen;        
    }
};