class Solution {
  public:
    int recur_count(vector<int>& coins, int n, int sum, vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(sum<0 || n==0) return 0;
        
        if(dp[n-1][sum]!=-1) return dp[n-1][sum];
        
        return dp[n-1][sum]=recur_count(coins, n, sum- coins[n-1], dp) +
               recur_count(coins, n-1, sum, dp);
    }
    
    int count(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return recur_count(coins, coins.size(), sum, dp);
    }
};
