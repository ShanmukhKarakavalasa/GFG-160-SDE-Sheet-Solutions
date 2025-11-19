class Solution {
  public:
    int count(int n, vector<int>& dp){
        if(dp[n]!=-1) return dp[n];
        if(n==0 || n==1){
            dp[n]=1;
            return 1;
        }
        
        int a=count(n-1, dp);
        int b;
        if(n>=2){
            b=count(n-2, dp);
        }
        
        return dp[n]=a+b;
    }
    
    int countWays(int n) {
        vector<int> dp(n+1,-1);
        int ans=count(n, dp);
        return ans;
    }
};
