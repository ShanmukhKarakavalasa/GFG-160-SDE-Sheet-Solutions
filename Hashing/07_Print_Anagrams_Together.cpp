class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        int n=arr.size();
        vector<vector<string>> ans;
        vector<string> temp(arr.begin(), arr.end());
        map<string, vector<string>> mp;
        
        for(int i=0;i<n;i++){
            sort(temp[i].begin(), temp[i].end());
        }
        
        for(int i=0;i<n;i++){
            if(mp.find(temp[i])!=mp.end()){
                mp[temp[i]].push_back(arr[i]);
            }
            else{
                mp[temp[i]]={arr[i]};
            }
        }
        
        for(auto i:mp){
            vector<string> t;
            for(auto val: i.second){
                t.push_back(val);
            }
            ans.push_back(t);
        }
        
        return ans;
        
    }
};
