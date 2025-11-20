class Solution {
  public:
    int find_cost(int i, vector<int>& dp, vector<int>& cost){
        if(i==0 || i==1){
            return dp[i]=cost[i];
        }
        
        if(dp[i]!=-1) return dp[i];
        
        return dp[i]=cost[i]+min(find_cost(i-1, dp, cost), find_cost(i-2, dp, cost));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1, -1);
        return min(find_cost(n-1,dp,cost), find_cost(n-2, dp,cost));
        
    }
};
