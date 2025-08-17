class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n=arr.size();
        vector<int> ans;
        map<int, int> mp;
        int left=0, right=k-1;
        
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        ans.push_back(mp.size());
        
        int out=arr[left];
        left++;
        right++;
        while(right<n){
            mp[out]--;
            if(mp[out]==0){
                mp.erase(out);
            }
            
            mp[arr[right]]++;
            ans.push_back(mp.size());
            
            out=arr[left];
            left++;
            right++;
        }
        
        return ans;
    }
};
