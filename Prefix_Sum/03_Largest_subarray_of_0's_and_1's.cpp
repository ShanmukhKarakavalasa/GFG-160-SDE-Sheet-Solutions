class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n=arr.size();
        int ans=0;
        map<int, int> mp;
        vector<int> aux(n);
        
        for(int i=0;i<n;i++){
            if(arr[i]==0) arr[i]=-1;
        }
        
        aux[0]=arr[0];
        
        for(int i=0;i<n;i++){
            aux[i]=arr[i]+aux[i-1];
        }
        
        for(int i=0;i<n;i++){
            if(aux[i]==0){
                ans=max(ans, i+1);
            }
            
            else if(mp.find(aux[i])!=mp.end()){
                ans=max(ans, i-mp[aux[i]]);
            }
            
            if(mp.find(aux[i])==mp.end()){
                mp[aux[i]]=i;
            }
        }
        
        return ans;
        
    }
};
