class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        vector<pair<double,int>> dist;
        int index=0;
        
        
        for(auto i:points){
            dist.push_back({sqrt(i[0]*i[0] + i[1]*i[1]), index++});
        }
        
        sort(dist.begin(), dist.end());
        
        index=0;
        while(k--){
            pair<double,int> temp= dist[index++];
            int idx=temp.second;
            
            ans.push_back(points[idx]);
        }
        
        return ans;
        
    }
};
