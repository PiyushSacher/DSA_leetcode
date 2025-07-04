class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>hash(3,-1);
        int count=0;
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']=i;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                //remember the formula
                count+=1+min({hash[0],hash[1],hash[2]});
            }
        }
        return count;
    }
};