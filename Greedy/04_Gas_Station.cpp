class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int a=accumulate(gas.begin(), gas.end(),0);
        int b=accumulate(cost.begin(), cost.end(),0);
        
        if(b>a) return -1;
        
        int n=gas.size();
        int total=0;
        int res=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            
            if(total<0){
                total=0;
                res=i+1;
            }
        }
        
        return res;
    }
};
