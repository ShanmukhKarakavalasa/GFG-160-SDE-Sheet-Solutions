class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int count=0;
        for(auto i: arr){
            if(i==target) count++;
            if(i>target) break;
        }
        
        return count;
    }
};
