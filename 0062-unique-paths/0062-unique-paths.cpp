class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int i,int j,int m,int n){
        if(i>=m || j>=n || i<0 || j<0) return 0;
        if(i==m-1|| j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=f(i,j+1,m,n)+f(i+1,j,m,n);
    }
    int uniquePaths(int m, int n) {
        dp.resize(105,vector<int>(105,-1));

        return f(0,0,m,n);        
    }
};