class Solution {
  public:
    int helper(string& s1, string& s2, int i, int j, int m, int n, 
    vector<vector<int>>& memo){
        if(memo[i][j]!=-1) return memo[i][j];
        
        if(i==m && j==n){
            return memo[i][j]=0;
        }
        
        if(i==m){
            return memo[i][j]=n-j;
        }
        
        if(j==n){
            return memo[i][j]=m-i;
        }
        
        if(s1[i]==s2[j]){
            return memo[i][j]= helper(s1, s2, i+1, j+1, m, n, memo);
        }
        
        return memo[i][j]=1+min({helper(s1, s2, i, j+1, m, n, memo),
                                 helper(s1, s2, i+1, j, m, n, memo),
                                 helper(s1, s2, i+1, j+1, m, n, memo)});
                   
    }
    
    int editDistance(string& s1, string& s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        
        int ans= helper(s1, s2, 0, 0, m, n, memo);
        
        return ans;
    }
};
