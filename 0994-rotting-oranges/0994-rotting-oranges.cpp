class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        //initial confi for bfs
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int time=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tm=q.front().second;
            q.pop();

            time=max(time,tm);           
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol]=2;
                }
            }            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0) return -1;
            }
        }
        return time;
    }
};