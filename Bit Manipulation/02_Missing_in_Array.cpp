class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n=arr.size();
        int xor1=0, xor2=0;
        
        for(int i=1;i<=n+1;i++){
            xor1^=i;
        }
        
        for(int i=0;i<n;i++){
            xor2^=arr[i];
        }
        
        return xor1^xor2;
        
    }
};
