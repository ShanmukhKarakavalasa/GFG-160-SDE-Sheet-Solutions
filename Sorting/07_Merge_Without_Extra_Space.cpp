class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int m=a.size();
        int n=b.size();
        
        int gap=(m+n+1)/2;
        
        while(gap>0){
            int i=0, j=gap;
            
            while(j<m+n){
                if(j<m && a[i]>a[j]){
                    swap(a[i], a[j]);
                }
                else if(i<m && j>=m && a[i]>b[j-m]){
                    swap(a[i], b[j-m]);
                }
                else if(i>=m && b[i-m]>b[j-m]){
                    swap(b[i-m],b[j-m]);
                }
                
                i++;
                j++;
            }
            
            if(gap==1) break;
            
            gap=(gap+1)/2;
        }
        
    }
};
