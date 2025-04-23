class Solution {
public:
    string reverseWords(string s) {
        for(int i=0;i<s.size();){
            if(s[i]!=' '){//it means it is a word
                int j=i;
                while(j<s.size() && s[j]!=' ') j++;
                reverse(begin(s)+i,begin(s)+j);
                i=j;
            }  
            i++;
        }
        return s;
        
    }
    
};