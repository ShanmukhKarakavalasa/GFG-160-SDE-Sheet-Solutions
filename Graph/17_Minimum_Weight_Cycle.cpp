class Solution {
  public:
    int dij(int V, vector<vector<vector<int>>>& adj, int src, int dest){
        vector<int> dist(V, INT_MAX);
        dist[src]=0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            pair<int, int> p=pq.top();
            pq.pop();
            int d=p.first;
            int u=p.second;
            
            if(d>dist[u]) continue;
            
            for(auto& neig: adj[u]){
                int v=neig[0];
                int w=neig[1];
                
                if((u==src && v==dest) || (u==dest && v==src)) continue;
                
                if(dist[v]> dist[u]+w){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[dest];
    }
    
    int findMinCycle(int V, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(V);
        for(auto i: edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        int res=INT_MAX;
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            int cycleD=dij(V, adj, u, v);
            
            if(cycleD!=INT_MAX){
                res=min(res, cycleD+w);
            }
        }
        
        return res;
    }
};
