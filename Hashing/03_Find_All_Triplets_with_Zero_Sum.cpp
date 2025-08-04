class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_map<int, unordered_set<int>> m; //number- {indexes}
        
        for(int i=0;i<n-1;i++){
            unordered_map<int, unordered_set<int>> m;
            
            for(int j=i+1;j<n;j++){
                if(m.find(0-arr[i]-arr[j])!=m.end()){
                    
                    //check for all the indexes of the given key(number)
                    for(auto& index: m[0-arr[i]-arr[j]]){
                        if(i!=j && j!=index){
                            vector<int> temp;
                            //insert the index triplet
                            temp.insert(temp.end(),{i,j, index});
                    
                            sort(temp.begin(), temp.end());
                    
                            ans.push_back(temp);
                        }
                    }
                    
                }
                
                //insert the index for the number
                m[arr[j]].insert(j);
            }
            //clear the map for every iteration
            m.clear();
        }
        
        return ans;
    }
};
