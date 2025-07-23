class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m=a.size(), n=b.size();
        int left=0, right=0;
        int temp=1;
        
        while(left<m && right<n){
            if(temp==k){
                return (a[left]<b[right])?a[left]:b[right];
            }
            if(a[left]<b[right]){
                left++;
                temp++;
            }
            else{
                right++;
                temp++;
            }
        }
        
        while(left<m){
            if(temp==k){
                return a[left];
            }
            
            left++;
            temp++;
        }
        
         while(right<n){
            if(temp==k){
                return b[right];
            }
            
            right++;
            temp++;
        }
        
        return (a[left]<b[right])?a[left]:b[right];
        
    }
};
