class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        int k=strs[0].size();

        if(strs.size()==1) return 0;
        for(int i=0;i<k;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]<strs[j-1][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
        
    }
};