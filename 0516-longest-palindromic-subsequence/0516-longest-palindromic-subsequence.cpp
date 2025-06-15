class Solution {
public:
    int f(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]) return 1+f(i-1,j-1,text1,text2,dp);
        return dp[i][j]=0+max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        
        string s2;
        int j=0;
        for(int i=n-1;i>=0;i--) s2.push_back(s[i]);

        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(n-1,n-1,s,s2,dp);   
    }
};