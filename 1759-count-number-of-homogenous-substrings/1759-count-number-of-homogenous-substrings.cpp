class Solution {
public:
    int countHomogenous(string s) {
        int MOD=1e9+7;

        int length;
        int result=0;
        for (int i=0;i<s.size();i++){
            if(i>0 && s[i]==s[i-1]){
                length+=1;
            }
            else{
                length=1;
            }
            result=(result+length)%MOD;
        }   
        return result;    
    }
};