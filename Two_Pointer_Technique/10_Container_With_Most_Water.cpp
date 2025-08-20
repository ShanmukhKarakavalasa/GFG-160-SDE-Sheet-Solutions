class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int max_water=0;
        int n=arr.size();
        
        int left=0, right=n-1;
        while(left<right){
            max_water=max(max_water, (min(arr[left], arr[right]))*(right-left));
            if(arr[left]<arr[right]) left++;
            else right--;
        }
        
        return max_water;
        
    }
};
