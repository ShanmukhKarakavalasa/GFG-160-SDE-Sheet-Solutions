class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=sum;j++){
                dp[i][j]=INT_MAX;
                int take=INT_MAX, not_take=INT_MAX;
                
                if(j-coins[i]>=0){
                    take=dp[i][j-coins[i]];
                    
                    if(take!=INT_MAX) take++;
                }
                
                if(i+1<coins.size()){
                    not_take=dp[i+1][j];
                }
                
                dp[i][j]=min(take, not_take);
            }
        }
        
        if(dp[0][sum]!=INT_MAX) return dp[0][sum];
        
        return -1;
    }
};
