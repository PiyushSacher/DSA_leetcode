class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>> &obstacleGrid){
        //make this line as 1st to check if the dest cell is an obstacle else all test case will not pass
        if(i<0 || i>=m || j<0|| j>=n || obstacleGrid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        

        int down=f(i+1,j,m,n,dp,obstacleGrid);
        int right=f(i,j+1,m,n,dp,obstacleGrid);
        
        return dp[i][j]=down+right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(0,0,m,n,dp,obstacleGrid);
    }
};