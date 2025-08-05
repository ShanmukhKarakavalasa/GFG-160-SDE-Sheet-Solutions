class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        set<int> s;
        map<int, int> mp;
        
        for(auto i: a){
            mp[i]++;
        }
        
        for(auto i: b){
            if(mp.find(i)!=mp.end()){
                s.insert(i);
            }
        }
        
        vector<int> v(s.begin(), s.end());
        
        return v;
    }
};
