class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n=prices.size();
        int max_profit=0;
        int current_profit=INT_MIN;
        int local_min=INT_MAX, local_max=INT_MIN;
        
        if(n==1) return 0;
        
        for(int i=0;i<n-1;i++){
            if(prices[i]>prices[i+1]){
                local_max=max(local_max, prices[i]);
                if(local_max!=INT_MIN && local_min!=INT_MAX)
                max_profit+=(local_max-local_min);
                local_max=INT_MIN;
                local_min=prices[i+1];
            }
            
            else if(prices[i]<=prices[i+1]){
                local_min=min(local_min, prices[i]);
            }
            
        }
        
        if(prices[n-2]<=prices[n-1]){
            max_profit+=(prices[n-1]-local_min);
        }
        
        return max_profit;
    }
};
