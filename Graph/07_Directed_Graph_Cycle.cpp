class Solution {
  public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis, int i){
        vis[i]=true;
        pathVis[i]=true;
        
        for(auto it: adj[i]){
            if(vis[it] && pathVis[it]) return true;
            if(!vis[it]){
                if(dfs(adj, vis, pathVis, it)){
                    return true;
                }
            }
        }
        
        pathVis[i]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> vis(V, false), pathVis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj, vis, pathVis, i)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
