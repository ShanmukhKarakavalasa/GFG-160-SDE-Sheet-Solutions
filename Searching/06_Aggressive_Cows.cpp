class Solution {
  public:
    bool check(vector<int> &stalls, int k, int dist){
        int count=1;
        int previous_stall=stalls[0];
        
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-previous_stall>=dist){
                count++;
                previous_stall=stalls[i];
            }
        }
        
        return count>=k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int low=1;
        int high=stalls[n-1]-stalls[0];
        int res=0;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(check(stalls, k, mid)){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return res;
    }
};
