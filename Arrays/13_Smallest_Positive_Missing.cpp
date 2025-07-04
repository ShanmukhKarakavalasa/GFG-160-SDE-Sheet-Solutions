class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n=arr.size();
        vector<int> v(n, INT_MIN);
        
        for(int i=0;i<n;i++){
            if(arr[i]>0 && arr[i]<=n){
                v[arr[i]-1]=INT_MAX;
            }
        }
        
        for(int i=0;i<n;i++){
            if(v[i]!=INT_MAX){
                return i+1;
            }
        }
        
        return n+1;
    }
};
