class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=0;
        map<int, int> mp;
        vector<int> aux(n);
        aux[0]=arr[0];
        
        for(int i=1;i<n;i++){
            aux[i]=arr[i]+aux[i-1];
        }
        
        for(int i=0;i<n;i++){
            if(aux[i]==k){
                ans=max(ans, i+1);
            }
            
            else if(mp.find(aux[i]-k)!=mp.end()){
                ans=max(ans, i-mp[aux[i]-k]);
            }
            
            if(mp.find(aux[i])==mp.end()){
                mp[aux[i]]=i;
            }
        }
        
        return ans;
        
    }
};
