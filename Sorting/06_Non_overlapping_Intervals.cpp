class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int count=0;
        int n=intervals.size();
        
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b){
            return a[1]<b[1];
        });
        
        int cur_end=intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(cur_end>intervals[i][0]){
                count++;
                cur_end=min(cur_end,intervals[i][1]);
            }
            else{
                cur_end=intervals[i][1];
            }
        }
        
        return count;
        
    }
};
