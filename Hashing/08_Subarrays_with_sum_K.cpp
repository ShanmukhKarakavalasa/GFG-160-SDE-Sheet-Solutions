class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        map<int, int> mp;
        int n=arr.size();
        int cur_sum=0;
        int res=0;
        
        for(int i=0;i<n;i++){
            cur_sum+=arr[i];
            
            if(cur_sum==k){
                res++;
            }
            if(mp.find(cur_sum-k)!=mp.end()){
                res+=mp[cur_sum-k];
            }
            
            mp[cur_sum]++;
        }
        
        return res;
        
    }
};
