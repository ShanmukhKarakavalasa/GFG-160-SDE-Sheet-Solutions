class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        int ans=0;
        
        vector<int> left(n);
        vector<int> right(n);
        int lmax=arr[0], rmax=arr[n-1];
        
        for(int i=1;i<n-1;i++){
            left[i]=max(lmax,arr[i]);
            lmax=left[i];
        }
        
        for(int i=n-2;i>=1;i--){
            right[i]=max(rmax,arr[i]);
            rmax=right[i];
        }
        
        for(int i=1;i<n-1;i++){
            int sum=(min(left[i], right[i]))-arr[i];
            if(sum>0) ans+=sum;
        }
        
        return ans;
    }
};
