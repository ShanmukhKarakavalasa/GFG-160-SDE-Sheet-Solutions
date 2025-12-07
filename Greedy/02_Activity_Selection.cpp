class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> v;
        int n=start.size();
        
        for(int i=0;i<n;i++){
            v.push_back({finish[i], start[i]});
        }
        
        sort(v.begin(), v.end());
        
        int res=1;
        int prev_end=v[0].first;
        
        for(int i=1;i<n;i++){
            if(v[i].second>prev_end){
                res++;
                prev_end=v[i].first;
            }
        }
        
        return res;
    }
};
