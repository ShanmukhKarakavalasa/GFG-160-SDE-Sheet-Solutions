class Solution {
  public:
    int findlcs(string &s1, string &s2, int i, int j, int m, int n,
    vector<vector<int>>& dp){
        if(i==m || j==n){
            return dp[i][j]=0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]){
            return dp[i][j]=1+ findlcs(s1, s2, i+1, j+1, m, n, dp);
        }
        
        if(s1[i]!=s2[j]){
            return dp[i][j]=max(findlcs(s1, s2, i, j+1, m, n, dp), 
                        findlcs(s1, s2, i+1, j, m, n, dp));
        }
    }
    int lcs(string &s1, string &s2) {
        //assume it as a grid and then based on match and mismatch assign values to it
        int m=s1.size();
        int n=s2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return findlcs(s1, s2, 0, 0, m, n, dp);
    }
};
