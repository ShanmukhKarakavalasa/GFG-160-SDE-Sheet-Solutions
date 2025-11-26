class Solution {
  public:
    bool isSubset(int i, int sum, vector<int>& arr,
    vector<vector<int>>& memo){
        if(sum==0) return 1;
        if(i<=0) return 0;
        if(memo[i][sum]!=-1) return memo[i][sum];
        
        if(arr[i-1]>sum){
            return memo[i][sum]=isSubset(i-1, sum, arr, memo);
        }
        else{
            return memo[i][sum]=isSubset(i-1, sum, arr, memo) ||
                                isSubset(i-1, sum-arr[i-1], arr, memo);
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>> memo(n+1, vector<int>(sum+1, -1));
        
        return isSubset(n, sum, arr, memo);
    }
};
