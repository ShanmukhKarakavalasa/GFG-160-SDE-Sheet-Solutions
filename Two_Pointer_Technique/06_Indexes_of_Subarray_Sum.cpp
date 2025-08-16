class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        vector<int> ans;
        int n=arr.size();
        int left=0, right=0;
        int cur_sum=arr[0];
        
        while(right<n){
            if(cur_sum==target){
                return {left+1, right+1};
            }
            else if(cur_sum<target){
                right++;
                cur_sum+=arr[right];
            }
            else{
                cur_sum-=arr[left];
                left++;
            }
        }
        
        return {-1};
    }
};
