class Solution {
public:
    void bfs(int i,int j,int n,int m,vector<vector<char>>&grid,vector<vector<int>>&visited){
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int nrow=row+delrow[k];
                int ncol=col+delcol[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && visited[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,n,m,grid,visited);                    
                }
            }
        }
        return cnt;
    }
};