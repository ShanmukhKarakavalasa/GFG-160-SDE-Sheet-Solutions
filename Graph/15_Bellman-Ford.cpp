class Solution {
  public:
    vector<int> isEqual(vector<int>& dist, vector<int>& temp){
        for(int i=0;i<dist.size();i++){
            if(dist[i]!=temp[i]){
                return {-1};
            }
        }
        
        return dist;
    }
    
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 100000000);
        dist[src]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                if((dist[it[0]]!=100000000 || dist[it[1]]!=100000000) && dist[it[0]]+it[2]<dist[it[1]]){
                    dist[it[1]]=dist[it[0]]+it[2];
                }
            }
        }
        
        vector<int> temp=dist;
        
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                if((dist[it[0]]!=100000000 || dist[it[1]]!=100000000) && dist[it[0]]+it[2]<dist[it[1]]){
                    temp[it[1]]=temp[it[0]]+it[2];
                }
            }
        }
        
        return isEqual(dist, temp);
    }
};
