#include<bits/stdc++.h>
class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n=s.size();
        set<string> word_set(dictionary.begin(), dictionary.end());
        
        int maxi_len=INT_MIN;
        for(string i: dictionary){
            int siz=i.size();
            maxi_len=max(maxi_len, siz);
        }
        
        vector<bool> dp(n+1, false);
        
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=max(0, i-maxi_len);j--){
                if(dp[j] && word_set.find(s.substr(j, i-j))!=word_set.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
