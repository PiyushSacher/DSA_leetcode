class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&board,vector<vector<int>>&visited){
        int n=board.size();
        int m=board[0].size();
        visited[row][col]=1;

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,visited);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && visited[0][i]==0) dfs(0,i,board,visited);
            if(board[n-1][i]=='O' && visited[n-1][i]==0) dfs(n-1,i,board,visited);
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && visited[i][0]==0) dfs(i,0,board,visited);
            if(board[i][m-1]=='O' && visited[i][m-1]==0) dfs(i,m-1,board,visited);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && board[i][j]=='O') board[i][j]='X';
            }
        }        
    }
};