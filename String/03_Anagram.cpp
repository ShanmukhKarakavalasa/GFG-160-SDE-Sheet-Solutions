class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        int m=s1.size(), n=s2.size();
        if(m!=n) return false;
        
        map<char, int> mp;
        for(auto i: s1){
            mp[i]++;
        }
        
        for(auto i: s2){
            if(mp.find(i)==mp.end()){
                return false;
            }
            mp[i]--;
        }
        
        for(auto i: mp){
            if(i.second!=0){
                return false;
            }
        }
        
        return true;
        
    }
};
