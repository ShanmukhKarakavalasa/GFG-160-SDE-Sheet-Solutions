class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> q;
        int s=0;
        int n=adj.size();
        vector<int> vis(n, 0);
        vector<int> res;
        
        res.push_back(s);
        vis[s]=1;
        q.push(s);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(auto i:adj[curr]){
                if(vis[i]==0){
                    q.push(i);
                    res.push_back(i);
                    vis[i]=1;
                }
            }
        }
        
        return res;
        
    }
};
