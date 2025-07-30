class Solution {
  public:
    bool binary_search(vector<vector<int>> &mat, int row, int x){
        int m=mat.size(), n=mat[0].size();
        int left=0, right=n-1;
        while(left<=right){
            int mid=(right+left)/2;
            
            if(mid>=0 && mid<=n-1 && mat[row][mid]==x) return true;
            if(mid>=0 && mid<=n-1 && mat[row][mid]>x) right=mid-1;
            else left=mid+1;
        }
        
        return false;
    }
    
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int m=mat.size(), n=mat[0].size();
        for(int i=0;i<m;i++){
            bool ans=binary_search(mat, i, x);
            if(ans) return true;
        }
        
        return false;
    }
};
