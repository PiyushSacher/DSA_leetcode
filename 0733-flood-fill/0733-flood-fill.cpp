class Solution {
public:
    void bfs(int sr,int sc,vector<vector<int>>&image,vector<vector<int>>&ans,int color,int inicolor){
        int n=image.size();
        int m=image[0].size();
        ans[sr][sc]=color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==inicolor && ans[nrow][ncol]!=color){
                    q.push({nrow,ncol});
                    ans[nrow][ncol]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        bfs(sr,sc,image,ans,color,inicolor);
        return ans;
    }
};