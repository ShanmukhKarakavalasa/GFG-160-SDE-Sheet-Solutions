class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        set<int> s;
        for(auto i: a){
            s.insert(i);
        }
        
        for(auto i: b){
            s.insert(i);
        }
        
        return s.size();
        
    }
};
