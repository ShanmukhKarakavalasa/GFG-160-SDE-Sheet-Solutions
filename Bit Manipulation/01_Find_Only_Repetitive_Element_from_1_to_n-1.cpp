class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int n=arr.size();
        int x1=0, x2=0;
        
        for(int i=0;i<n;i++){
            x1^=arr[i];
        }
        
        
        for(int i=1;i<=n-1;i++){
            x2^=i;
        }
        
        return x1^x2;
    }
};
