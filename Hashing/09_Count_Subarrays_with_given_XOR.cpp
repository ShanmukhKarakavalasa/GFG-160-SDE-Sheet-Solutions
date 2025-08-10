class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long res=0;
        int cur_xor=0;
        int n=arr.size();
        map<int, int> mp;
        
        for(int i=0;i<n;i++){
            cur_xor^=arr[i];
            
            if(cur_xor==k){
                res++;
            }
            if(mp.find(cur_xor^k)!=mp.end()){
                res+=mp[cur_xor^k];
            }
            
            mp[cur_xor]++;
        }
        
        return res;
        
        
    }
};
