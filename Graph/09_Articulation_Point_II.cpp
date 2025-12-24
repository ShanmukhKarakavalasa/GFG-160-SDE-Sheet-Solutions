class Solution {
  public:
    void arti_points(vector<vector<int>>& adj, int u, vector<int>& dist,
    vector<int>& low, vector<int>& vis, vector<int>& isAP, int& t,
    int parent){
        vis[u]=1;
        t++;
        dist[u]=low[u]=t;
        int children=0;
        
        for(int v: adj[u]){
            if(!vis[v]){
                children++;
                arti_points(adj, v, dist, low, vis, isAP, t, u);
                
                low[u]=min(low[u], low[v]);
                
                if(parent!=-1 && low[v]>=dist[u]){
                    isAP[u]=1;
                }
            }
            else if(v!=parent){
                low[u]=min(low[u], dist[v]);
            }
        }
        
        if(parent==-1 && children>1){
            isAP[u]=1;
        }
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &i: edges){
            int u=i[0];
            int v=i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(V,0), low(V,0), vis(V,0), isAP(V,0);
        int t=0;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                arti_points(adj, i, dist, low, vis, isAP, t, -1);
            }
        }
        
        vector<int> res;
        for(int i=0;i<V;i++){
            if(isAP[i]){
                res.push_back(i);
            }
        }
        
        if(res.empty()) return {-1};
        return res;
    }
};
