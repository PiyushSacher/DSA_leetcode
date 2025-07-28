class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        if(grid[n-1][m-1]==0 && n==1 && m==1) return 1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;

            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=r+delrow;
                    int ncol=c+delcol;

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                        dist[nrow][ncol]=1+dis;
                        if(nrow==n-1 && ncol==m-1) return dis+1;
                        q.push({1+dis,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
        
    }
};