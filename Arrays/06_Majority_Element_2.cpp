class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        vector<int> ans;
        
        int n=arr.size();
        map<int, int> mp;
        int th=n/3;
        
        for(auto i: arr){
            mp[i]++;
        }
        
        for(auto i:mp){
            if(i.second>th){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};
