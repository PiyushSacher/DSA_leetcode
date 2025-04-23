class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        for(int i=0;i<haystack.size()-needle.size()+1;i++){
            if(haystack[i]==needle[0]){
                if(haystack.substr(i,needle.size())==needle) return i;
            }
        }  
        return -1;   
    }
};