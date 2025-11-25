class Solution {
  public:
    int can_reach(vector<int>& arr){
        int n=arr.size();
        int goal=n-1;
        
        for(int i=goal;i>=0;i--){
            if(i+arr[i]>=goal){
                goal=i;
            }
        }
        
        if(goal==0) return 1;
        return 0;
    }
    int minJumps(vector<int>& arr) {
        int ans=can_reach(arr);
        if(ans==0) return -1;
        
        int n=arr.size();
        int res=0;
        int left=0, right=0;
        int farthest;
        
        while(right<n-1){
            farthest=0;
            for(int i=left;i<=right;i++){
                farthest=max(farthest, arr[i]+i);
            }
            
            left=right+1;
            right=farthest;
            res++;
        }
        
        return res;
    }
};
