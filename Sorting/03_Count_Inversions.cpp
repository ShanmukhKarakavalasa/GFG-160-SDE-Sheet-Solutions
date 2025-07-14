class Solution {
  public:
    int merge(vector<int>& arr, int s, int m, int e){
        int n1=m-s+1;
        int n2=e-m;
        vector<int> a(n1);
        vector<int> b(n2);
        
        for(int i=0;i<n1;i++){
            a[i]=arr[i+s];
        }
        for(int i=0;i<n2;i++){
            b[i]=arr[i+m+1];
        }
        
        int res=0;
        int i=0, j=0, k=s;
        
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                arr[k]=a[i];
                i++;
                k++;
            }
            else{
                arr[k]=b[j];
                j++;
                k++;
                res+=(n1-i);
            }
        }
        
        while(i<n1){
            arr[k]=a[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=b[j];
            j++;
            k++;
        }
        
        return res;
    }
  
    int partition(vector<int>& arr, int s, int e){
        int count=0;
        if(s<e){
            int mid=(s+e)/2;
            count+=partition(arr, s, mid);
            count+=partition(arr, mid+1, e);
            
            count+=merge(arr, s, mid, e);
        }
        
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        return partition(arr,0,n-1);
    }
};
