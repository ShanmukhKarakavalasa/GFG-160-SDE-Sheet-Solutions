class Solution {
  public:   
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int m=mat.size(), n=mat[0].size();
        
        int left=0, right=(m*n)-1;
        
        while(left<=right){
            int mid=(left+right)/2;
            
            if(mat[mid/n][mid%n]==x) return true;
            else if(x<mat[mid/n][mid%n]) right=mid-1;
            else left=mid+1;
        }
        
        return false;
        
    }
};
