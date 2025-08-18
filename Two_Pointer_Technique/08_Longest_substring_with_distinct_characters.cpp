class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n=s.size();
        int maxi=INT_MIN;;
        vector<int> v(26,-1);
        int left=0, right=0;
        
        while(right<n){
            left=max(left, v[s[right]-'a']+1);
            maxi=max(maxi, right-left+1);
            v[s[right]-'a']=right;
            right++;
        }
        
        return maxi;
        
    }
};
