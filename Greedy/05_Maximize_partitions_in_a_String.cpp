class Solution {
  public:
    int maxPartitions(string &s) {
        int n=s.size(); 
        int res=0;
        
        map<char, int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        
        int till=-1;
        
        for(int i=0;i<n;i++){
            till=max(till, mp[s[i]]);
            
            if(till==i){
                res++;
            }
        }
        
        return res;
        
    }
};
