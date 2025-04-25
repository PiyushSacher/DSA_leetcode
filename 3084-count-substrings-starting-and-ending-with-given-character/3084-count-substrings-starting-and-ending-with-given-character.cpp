class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count=0;
        long long res=0;  // Final count 
        
        for (char ch:s) {
            if(ch==c){
                count++;  
                res+=count; 
            }
        }
        return res;
    }
};