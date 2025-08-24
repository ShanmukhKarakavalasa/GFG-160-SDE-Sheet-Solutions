class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n, 0);
        int zeros=0, prod=1;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zeros++;
            }
            else{
                prod*=arr[i];
            }
        }
        
        if(zeros>1) return ans;
        if(zeros==1){
            for(int i=0;i<n;i++){
                if(arr[i]==0){
                    ans[i]=prod;
                }
            }
            return ans;
        }
        
        for(int i=0;i<n;i++){
            ans[i]=prod/arr[i];
        }
        
        return ans;
    }
};
