class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        //dest cell , return its value as it will be included in all paths
        if(i==m-1 && j==n-1) return grid[i][j];

        //as if is goes out of bound, then this path can never be our answer
        if(i<0 || i>=m || j<0 || j>=n) return 1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        int down=f(i+1,j,m,n,grid,dp);
        int right=f(i,j+1,m,n,grid,dp);

        return dp[i][j]=grid[i][j]+min(down,right);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(0,0,m,n,grid,dp);
        
    }
};