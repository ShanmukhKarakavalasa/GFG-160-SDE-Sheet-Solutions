class Solution {
  public:
    
    int maxProduct(vector<int> &arr) {
        int curmin=arr[0], curmax=arr[0], maxprod=arr[0];
        int n=arr.size();
        
        for(int i=1;i<n;i++){
            int temp=min({arr[i], arr[i]*curmin, arr[i]*curmax});
            
            curmax=max({arr[i], arr[i]*curmin, arr[i]*curmax});
            
            curmin=temp;
            
            maxprod=max(maxprod, curmax);
        }
        
        return maxprod;
        
    }
};
