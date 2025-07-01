class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n= arr.size();
        int res=arr[0], curr_sum=0;
        
        for(int i=0;i<n;i++){
            curr_sum=max(curr_sum+arr[i], arr[i]);
            res=max(res, curr_sum);
        }
        
        return res;
        
    }
};
