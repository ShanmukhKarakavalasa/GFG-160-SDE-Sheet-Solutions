class Solution {
  public:
    void depthFirstSearch(vector<vector<int>>& adj, vector<int>& res, int s, vector<int>& vis){
        vis[s]=1;
        
        for(auto i:adj[s]){
            if(vis[i]==0){
                res.push_back(i);
                depthFirstSearch(adj, res, i, vis);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> res;
        vector<int> vis(n,0);
        
        int s=0;
        res.push_back(s);
        depthFirstSearch(adj, res, s, vis);
        
        return res;
    }
};
