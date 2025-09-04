class Solution {
  public:
    void permute(int n, string& curr, map<char, int>& mp, vector<string>& res){
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        
        for(pair<char, int> p:mp){
            char ch=p.first;
            int freq=p.second;
            
            if(freq==0) continue;
            
            curr.push_back(ch);
            mp[ch]--;
            
            permute(n, curr, mp, res);
            
            curr.pop_back();
            mp[ch]++;
        }
    }
    
    vector<string> findPermutation(string &s) {
        vector<string> res;
        string curr="";
        map<char, int> mp;
        
        for(auto c: s) mp[c]++;
        
        permute(s.size(), curr, mp, res);
        
        return res;
    }
};
