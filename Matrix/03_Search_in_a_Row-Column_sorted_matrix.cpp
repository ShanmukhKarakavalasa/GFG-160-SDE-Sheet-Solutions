class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int m=mat.size(), n=mat[0].size();
        int cur_row=-1;
        if(mat[0][0]>x || mat[m-1][n-1]<x) return false;
        
        int left=0, right=n-1;
        int top=0, bottom=m-1;
        //start at top right cell
        
        while(top>=0 && top<=m-1 && right>=0 && right<=n-1){
            if(x==mat[top][right]) return true;
            
            //skip the top row and move bottom
            if(top>=0 && top<=m-1 && right>=0 && right<=n-1 && x>mat[top][right]){
                top++;
            }
            
            //skip the right most col and move left
            if(top>=0 && top<=m-1 && right>=0 && right<=n-1 && x<mat[top][right]){
                right--;
            }
        }
        
        return false;
        
    }
};
