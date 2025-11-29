class Solution {
  public:
    int recur(vector<int> &prices, int k, int i, bool canBuy, 
    vector<vector<vector<int>>>& dp){
        if(k==0 || i==prices.size()) return 0;
        if(dp[i][k][canBuy]!=-1) return dp[i][k][canBuy];
        
        int pick=0, no_pick=0;
        if(canBuy==true){
            pick=-prices[i] + recur(prices, k, i+1, false, dp);
            no_pick= recur(prices, k, i+1, true, dp);
        }
        if(canBuy==false){
            pick=prices[i] + recur(prices, k-1, i+1, true, dp);
            no_pick= recur(prices, k, i+1, false, dp);
        }
        
        return dp[i][k][canBuy]= max(pick, no_pick);
    }
    
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return recur(prices, 2, 0, true, dp);
    }
};
