class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string start=strs[0];
        string end=strs[n-1];
        for(int i=0;i<start.length();i++){
            if(start[i]==end[i]) result+=start[i];
            else break;
        }
        return result;
    }
};