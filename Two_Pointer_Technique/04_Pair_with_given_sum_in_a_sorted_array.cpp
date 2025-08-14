class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n=arr.size();
        int left=0, right=n-1;
        map<int, int> mp;
        int ans=0;
        
        for(auto i:arr){
            mp[i]++;
        }
        
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum==target){
                int c1=mp[arr[left]];
                int c2=mp[arr[right]];
                int ele1=arr[left], ele2=arr[right];
                if(ele1==ele2){
                    ans+=((c1)*(c1-1))/2;
                }
                else{
                    ans+=c1*c2;
                }
                
                left++;
                while(ele1==arr[left]) left++;
                while(ele2==arr[right]) right--;
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        
        return ans;
    }
};
