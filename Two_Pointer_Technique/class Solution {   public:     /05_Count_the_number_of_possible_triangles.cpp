class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int res=0;
        int n=arr.size();
        int left, right;
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        
        for(int i=0;i<n-2;i++){
            left=i+1, right=n-1;
            while(left<right){
                if(arr[left]+arr[right]>arr[i]){
                    res+=(right-left);
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return res;
        
    }
};
