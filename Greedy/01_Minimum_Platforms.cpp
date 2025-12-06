class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        int i=0, j=0;
        int req_platforms=0, res=1;
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        while(i<n){
            if(arr[i]<=dep[j]){
                req_platforms++;
                res=max(res, req_platforms);
                i++;
            }
            else if(arr[i]>dep[j]){
                req_platforms--;
                res=max(res, req_platforms);
                j++;
            }
        }
        
        return res;
    }
};
