class Solution {
  public:
    char nonRepeatingChar(string &s) {
        int n=s.size();
        map<char, int> mp;
        vector<char> v;
        
        for(auto i: s){
            mp[i]++;
            v.push_back(i);
        }
        
        for(auto i: s){
            if(mp[i]>1){
                v.erase(remove(v.begin(), v.end(), i), v.end());
            }
        }
        
        if(v.size()>0) return v[0];
        return '$';
    }
};
