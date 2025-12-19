#define p pair<int, int>
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<p>> adj(V);
        
        for(auto i: edges){
            int a=i[0];
            int b=i[1];
            int d=i[2];
            
            adj[a].push_back({b,d});
            adj[b].push_back({a,d});
        }
        
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> dist(V, 999999);
        
        dist[src]=0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int source=pq.top().second;
            pq.pop();
            
            for(auto it: adj[source]){
                int wt=it.second;
                int edgenode=it.first;
                
                if(dis+wt < dist[edgenode]){
                    dist[edgenode]=dis+wt;
                    pq.push({dist[edgenode], edgenode});
                }
            }
            
        }
        
        return dist;
        
    }
};
