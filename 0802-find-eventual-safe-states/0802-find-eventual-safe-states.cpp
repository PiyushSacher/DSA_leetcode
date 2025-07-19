class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&graph,vector<int>&check){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,graph,check)==true) return true;
            }
            else{
                if(pathvis[it]==1) return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>visited(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,pathvis,graph,check);
            }
        }
        vector<int>safeNodes;
        for(int i=0;i<V;i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        return safeNodes;
        
    }
};