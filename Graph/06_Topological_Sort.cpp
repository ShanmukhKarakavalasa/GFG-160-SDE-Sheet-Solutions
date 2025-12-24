class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st,
    int i, int V){
        vis[i]=true;
        
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(adj, vis, st, it, V);
            }
        }
        
        st.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto i: edges){
            int u=i[0];
            int v=i[1];
            
            adj[u].push_back(v);
        }
        
        stack<int> st;
        vector<bool> vis(V, false);
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj, vis, st, i, V);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};
