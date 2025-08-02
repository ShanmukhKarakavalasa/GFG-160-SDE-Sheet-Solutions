class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        map<int, int> mp;
        for(auto i: arr){
            if(mp.find(target-i)!=mp.end()){
                return true;
            }
            
            mp[i]=1;
        }
        
        return false;
        
    }
};
