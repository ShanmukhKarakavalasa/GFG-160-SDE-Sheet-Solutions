class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n=arr.size();
        int maxi, mini;
        
        sort(arr.begin(), arr.end());
        
        int ans=arr[n-1]- arr[0];
        
        for(int i=1;i<n;i++){
            if(arr[i]-k<0) continue; //skip which give neagtive till possible negative comes
            
            maxi=max(arr[i-1]+k, arr[n-1]-k); //The max of before tower and the last tower
            mini=min(arr[i]-k, arr[0]+k); //The min of curr tower and first tower 
            
            ans=min(ans, maxi-mini); //Check for every possible difference
        }
        
        return ans;
        
    }
};
