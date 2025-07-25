class Solution {
  public:
    int count_students(vector<int> &arr, int x){
        int cur_sum=0;
        int number_of_students=1;
        
        for(int i=0;i<arr.size();i++){
            if(cur_sum+arr[i]<=x){
                cur_sum+=arr[i];
            }
            else{
                number_of_students++;
                cur_sum=arr[i];
            }
        }
        
        return number_of_students;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        int res;
        int l=INT_MIN,r=0;
        for(int i=0;i<n;i++){
            l=max(l,arr[i]);
            r+=arr[i];
        }
        
        while(l<=r){
            int mid=(l+r)/2;
            
            if(count_students(arr,mid)>k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        return l;
        
    }
};
