class Solution {
  public:
    int recur(int n, int W, vector<vector<int>>& dp,
    vector<int> &val, vector<int> &wt){
        if(n==0){
            if(wt[0]<=W) return dp[n][W]=val[0];
            else return dp[n][W]=0;
        }
        
        if(dp[n][W]!=-1) return dp[n][W];
        
        int not_pick=0+recur(n-1, W, dp, val, wt);
        int pick=INT_MIN;
        
        if(wt[n]<=W){
            pick=val[n]+recur(n-1, W-wt[n], dp, val, wt);
        }
        
        return dp[n][W]=max(not_pick, pick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return recur(n-1, W, dp, val, wt);
        
    }
};
