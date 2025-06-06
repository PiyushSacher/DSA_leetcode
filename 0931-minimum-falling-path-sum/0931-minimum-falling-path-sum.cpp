// class Solution {
// public:
//     int f(int i,int j,const vector<vector<int>>&matrix,vector<vector<int>>&dp){
//         int n=matrix.size();
//         if(j<0 || j>=n) return 1e9;
//         if(i==n-1) return matrix[i][j];
        
//         if(dp[i][j]!=-1) return dp[i][j];

//         int st=f(i+1,j,matrix,dp);
//         int leftdiag=f(i+1,j-1,matrix,dp);
//         int rightdiag=f(i+1,j+1,matrix,dp);

//         return dp[i][j]=matrix[i][j]+min({st,leftdiag,rightdiag});
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         int mini=INT_MAX;
//         for(int j=0;j<n;j++){
//             mini=min(mini,f(0,j,matrix,dp));
//         }
//         return mini;
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,0));

        
        for(int j=0;j<n;j++)
            dp[n-1][j]=matrix[n-1][j];

        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<n;j++) {
                int down = dp[i+1][j];
                int leftDiag =j>0 ? dp[i+1][j-1]:1e9;
                int rightDiag= j<n-1 ? dp[i+1][j+1]:1e9;

                dp[i][j] =matrix[i][j] +min({down,leftDiag,rightDiag});
            }
        }

        int mini=INT_MAX;
        for (int j=0;j<n;j++)
            mini=min(mini,dp[0][j]);

        return mini;
    }
};
