class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int n=arr.size();
        int totalSum=0, currLinearSum=0, currMinSum=0;
        int linearSum=arr[0], circularSum=arr[0], minSum=arr[0];
        
        for(int i=0;i<n;i++){
            currLinearSum=max(currLinearSum+arr[i], arr[i]);
            linearSum=max(linearSum, currLinearSum);
            
            currMinSum=min(currMinSum+arr[i], arr[i]);
            minSum=min(minSum, currMinSum);
            
            totalSum+=arr[i];
        }
        
        circularSum=totalSum-minSum;
        
        if(circularSum==linearSum) return linearSum;
        
        return max(circularSum, linearSum);
        
        
    }
};
