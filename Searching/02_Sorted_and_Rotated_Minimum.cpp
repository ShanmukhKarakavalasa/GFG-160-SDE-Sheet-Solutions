class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        if(n==2) return (arr[0]>arr[1])? arr[1]: arr[0];
        int left=0, right=n-1;
        
        if(arr[left]<arr[right]) return arr[left];
        
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]>arr[n-1] && mid+1<n && arr[mid]>arr[mid+1]){
                return arr[mid+1];
            }
            else if(arr[mid]>arr[n-1] && mid+1<n && arr[mid]<arr[mid+1]){
                left=mid+1;
            }
            
            if(arr[mid]<arr[n-1] && mid-1>=0 && arr[mid]<arr[mid-1]){
                return arr[mid];
            }
            else if(arr[mid]<arr[n-1] && mid-1>=0 && arr[mid]>arr[mid-1]){
                right=mid-1;
            }
        }
        
        return arr[0];
    }
};
