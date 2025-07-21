class Solution {
  public:
    int binary_search(vector<int>& arr, int key){
        int n=arr.size();
        int left=0, right=n-1;
        
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==key) return mid;
            else if(arr[mid]<key) left=mid+1;
            else right=mid-1;
        }
        
        return -1;
    }
    
    int search(vector<int>& arr, int key) {
        int n=arr.size();
        
        if(n==1 && arr[0]==key) return 0;
        else if(n==1) return -1;
        
        if(n==2 && arr[0]==key) return 0;
        else if(n==2 && arr[1]==key) return 1;
        else if(n==2) return -1;
        
        int left=0, right=n-1;
        if(arr[left]<arr[right]){
            return binary_search(arr, key);
        }
        
        //find the smallest number
        int smallest_index=-1;

        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==key) return mid;
            
            if(arr[mid]>arr[n-1] && mid+1<n && arr[mid]>arr[mid+1]){
                smallest_index=mid+1;
                break;
            }
            else if(arr[mid]>arr[n-1] && mid+1<n && arr[mid]<arr[mid+1]){
                left=mid+1;
            }
            
            if(arr[mid]<arr[n-1] && mid-1>=0 && arr[mid]<arr[mid-1]){
                smallest_index=mid;
                break;
            }
            else if(arr[mid]<arr[n-1] && mid-1>=0 && arr[mid]>arr[mid-1]){
                right=mid-1;
            }
            
        }
        
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[i]=arr[(smallest_index+i)%n];
        }
        
        left=0, right=n-1;
        if(binary_search(temp, key)==-1) return -1;
        else return (binary_search(temp, key)+(smallest_index))%n;
        
        return -1;
        
    }
};
