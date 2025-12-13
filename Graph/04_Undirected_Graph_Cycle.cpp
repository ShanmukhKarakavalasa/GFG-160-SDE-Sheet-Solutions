class Solution {
  public:
    bool bfs(vector<vector<int>>& adj, vector<bool>& visited,
    int start, int V){
        queue<pair<int, int>> q;
        q.push({start, -1});
        visited[start]=true;
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto i:adj[node]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push({i, node});
                }
                else if(i!=parent){
                    return true;
                }
            }
        }
        
        return false;
                
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        //convert edges to adjacency list
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i] && bfs(adj, visited, i, V)){
                return true;
            }
        }
        
        return false;
    }
};
