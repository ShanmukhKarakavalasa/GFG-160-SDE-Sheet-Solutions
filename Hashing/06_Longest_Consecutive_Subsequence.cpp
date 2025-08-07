
class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        map<int, int> mp;
        vector<int> v;
        int res=1, cur=1;
        
        for(auto i: arr){
            mp[i]++;
        }
        
        for(auto i:mp){
            v.push_back(i.first);
        }
        
        for(int i=0;i<v.size()-1;i++){
            if(v[i]+1==v[i+1]){
                cur++;
            }
            else{
                res=max(res, cur);
                cur=1;
            }
        }
        
        return max(res, cur);
    }
};
