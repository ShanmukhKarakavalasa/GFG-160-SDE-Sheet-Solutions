class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n= arr.size();
        int count=0;
        for(auto i: arr){
            if(i==0) count++;
        }
        
        if(count==0) return;
        if(count==n) return;
        
        int ptr=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                arr[ptr++]=arr[i];
            }
        }
        
        while(count--){
            arr[ptr++]=0;
        }
    }
};
