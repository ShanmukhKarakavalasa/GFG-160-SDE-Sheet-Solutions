class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n, -1);
        
        dp[0]=arr[0];
        dp[1]=max(arr[0], arr[1]);
        dp[2]=arr[2]+dp[0];
        
        for(int i=3;i<n;i++){
            dp[i]=arr[i]+max(dp[i-2], dp[i-3]);
        }
        
        return max(dp[n-1], dp[n-2]);
        
    }
};
