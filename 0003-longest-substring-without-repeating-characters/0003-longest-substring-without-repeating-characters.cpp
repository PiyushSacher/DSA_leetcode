class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mpp;
        int l=0,r=0,maxlen=0,len=0;;
        while(r<s.size()){
            if(mpp.find(s[r])!=mpp.end()){   // it means it exists
                if(mpp[s[r]]>=l) l=mpp[s[r]]+1;
            }
            len=r-l+1;
            maxlen=max(len,maxlen);
            mpp[s[r]]=r;
            r++;
        }
        return maxlen;
        
    }
};