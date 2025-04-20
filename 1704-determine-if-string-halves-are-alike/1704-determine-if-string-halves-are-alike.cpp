class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'|| ch=='A'|| ch=='E'|| ch=='I'|| ch=='O'|| ch=='U') return true;
        else return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int i=0;
        int j=n/2;
        int cntLeft=0;
        int cntRight=0;
        while(i<n/2 && j<n){
            if(isVowel(s[i])) cntLeft++;
            if(isVowel(s[j])) cntRight++;
            i++;
            j++;
        }
        return (cntLeft==cntRight);
    }
};