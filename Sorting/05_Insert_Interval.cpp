class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        vector<vector<int>> res;
        vector<vector<int>> temp;
        int n=intervals.size();
        int i, flag=0;
        for(i=0;i<n;i++){
            if(intervals[i][0]<newInterval[0]){
                temp.push_back({intervals[i][0], intervals[i][1]});
            }
            else{
                temp.push_back({newInterval[0], newInterval[1]});
                flag=1;
                break;
            }
        }

        if(flag==0){
            temp.push_back({newInterval[0], newInterval[1]});
        }
        else{
            for(int idx=i;idx<n;idx++){
                temp.push_back({intervals[idx][0], intervals[idx][1]});
            }
        }
        
        
        res.push_back(temp[0]);
        
        for(i=1;i<temp.size();i++){
            if(res[res.size()-1][1]>=temp[i][0]){
                res[res.size()-1][1]=max(res[res.size()-1][1], temp[i][1]);
            }
            else{
                res.push_back(temp[i]);
            }
        }
        
        return res;
        
        
    }
};
