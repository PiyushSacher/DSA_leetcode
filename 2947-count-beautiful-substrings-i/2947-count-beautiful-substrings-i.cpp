class Solution {
public:
    bool isvowel(char &ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;      

    }
    int beautifulSubstrings(string s, int k) {
        int result=0;
        for(int i=0;i<s.size();i++){
            int vowel=0;
            int conso=0;
            for(int j=i;j<s.size();j++){
                if(isvowel(s[j])) vowel++;
                else conso++;

                if(vowel==conso && ((vowel*conso)%k)==0) result+=1;
            }
        }
        return result;
        
    }
};