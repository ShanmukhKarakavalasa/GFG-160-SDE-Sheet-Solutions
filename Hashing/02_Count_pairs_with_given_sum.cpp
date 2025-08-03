class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        map<int, int> mp;
        int res=0;
        
        for(auto i: arr){
            if(mp.find(target-i)!=mp.end()){
                res+=mp[target-i];
            }
            mp[i]++;
        }
        
        return res;
        
    }
};
