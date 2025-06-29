class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n=prices.size();
        int max_profit=0;
        int curr_min=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(curr_min>prices[i]){
                curr_min=prices[i];
            }
            else{
                max_profit=max(max_profit, prices[i]-curr_min);
            }
        }
        
        return max_profit;
        
    }
};
