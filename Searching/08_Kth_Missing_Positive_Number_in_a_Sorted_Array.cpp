class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n=arr.size();
        int l=0, h=n-1;
        int res=k+n;
        
        while(l<=h){
            int mid=(l+h)/2;
            
            if(arr[mid]>k+mid){
                h=mid-1;
                res=k+mid;
            }
            else{
                l=mid+1;
            }
        }
        
        return res;
    }
};
