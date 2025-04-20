class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalLetters=0;
        for(char ch:word){
            if(isupper(ch)){
                capitalLetters++;
            }
        }

        if(capitalLetters==word.size() || capitalLetters==0 || (capitalLetters==1 && isupper(word[0]))){
            return true;
        }
        return false;
        
    }
};