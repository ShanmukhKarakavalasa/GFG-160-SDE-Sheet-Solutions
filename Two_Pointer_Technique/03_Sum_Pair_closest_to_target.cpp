class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n=arr.size();
        int min_dif=INT_MAX;
        int abs_dif=INT_MIN;
        int left=0, right=n-1;
        vector<int> v;
        
        sort(arr.begin(), arr.end());
        
        while(left<right){
            int cur_sum=arr[left]+arr[right];
            
            if(abs(cur_sum-target)<=min_dif){
                min_dif=abs(cur_sum-target);
            }
            
            if(cur_sum<=target){
                left++;
            }
            else{
                right--;
            }
        }
        
        left=0, right=n-1;
        while(left<right){
            int cur_sum=arr[left]+arr[right];
            
            if(abs(cur_sum-target)==min_dif && abs(arr[left]-arr[right])>abs_dif){
                abs_dif=abs(arr[left]-arr[right]);
                v.clear();
                v.push_back(arr[left]);
                v.push_back(arr[right]);
            }
            
            if(cur_sum<=target){
                left++;
            }
            else{
                right--;
            }
        }
        
        return v;
    }
};
