#define p pair<int, int>
class Solution {
  public:
    int cal_dist(vector<int>& a, vector<int>& b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    
    int minCost(vector<vector<int>>& houses) {
        int n=houses.size();
        
        priority_queue<p, vector<p>, greater<>> pq;
        vector<bool> vis(n, false);
        int res=0;
        
        pq.push({0,0});
        while(!pq.empty()){
            pair<int, int> val=pq.top();
            pq.pop();
            
            int dist=val.first;
            int u=val.second;
            
            if(vis[u]) continue;
            
            vis[u]=true;
            res+=dist;
            
            for(int v=0;v<n;v++){
                if(!vis[v]){
                    int d=cal_dist(houses[u], houses[v]);
                    pq.push({d, v});
                }
                
            }
        }
        
        return res;
        
    }
};
