class Solution {
  public:
    bool static comp(string& s1, string& s2){
        return s1.size()<s2.size();
    }
    
    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        
        map<string, int> mp;
        
        int res=1;
        
        for(string& w: words){
            mp[w]=1;
            
            for(int i=0;i<w.size();i++){
                string pred= w.substr(0, i) + w.substr(i+1);
                if(mp.find(pred)!=mp.end()){
                    mp[w]=max(mp[w], mp[pred]+1);
                }
            }
            
            res=max(res, mp[w]);
        }
        
        return res;
        
    }
};
