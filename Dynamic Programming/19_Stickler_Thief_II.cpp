class Solution {
  public:
    int maxValue(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp1(n-1);
        vector<int> dp2(n-1);
        
        dp1[0]=arr[0];
        dp1[1]=max(arr[1], arr[0]);
        dp1[2]=arr[2]+dp1[0];
        for(int i=3;i<n-1;i++){
            dp1[i]=arr[i]+max(dp1[i-2], dp1[i-3]);
        }
        
        
        dp2[0]=arr[1];
        dp2[1]=max(arr[1], arr[2]);
        dp2[2]=arr[3]+dp2[0];
        for(int i=3;i<n-1;i++){
            dp2[i]=arr[i+1]+max(dp2[i-2], dp2[i-3]);
        }
        
        return max({dp1[n-2], dp1[n-3], dp2[n-2], dp2[n-3]});
        
    }
};
