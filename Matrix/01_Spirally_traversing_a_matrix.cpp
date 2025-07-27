class Solution {
  public:
    bool all_visited(vector<vector<int>> &mat){
        int m=mat.size(), n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=-1){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int> ans;
        int m=mat.size(), n=mat[0].size();
        int left=0, right=n-1;
        int top=0, bottom=m-1;
        
        while(!all_visited(mat)){  
            
            for(int i=left;i<=right;i++){
                if(top>=0 && top<=m-1 && i>=0 && i<=n-1 && mat[top][i]!=-1){
                    ans.push_back(mat[top][i]);
                    mat[top][i]=-1;
                }
            }
            top++;
            
            for(int i=top;i<=bottom;i++){
                if(right>=0 && right<=n-1 && i>=0 && i<=m-1 && mat[i][right]!=-1){
                    ans.push_back(mat[i][right]);
                    mat[i][right]=-1;
                }
            }
            right--;
            
            for(int i=right;i>=left;i--){
                if(bottom>=0 && bottom<=m-1 && i>=0 && i<=n-1 && mat[bottom][i]!=-1){
                    ans.push_back(mat[bottom][i]);
                    mat[bottom][i]=-1;
                }
            }
            bottom--;
            
            for(int i=bottom;i>=top;i--){
                if(left>=0 && left<=n-1 && i>=0 && i<=m-1 && mat[i][left]!=-1){
                    ans.push_back(mat[i][left]);
                    mat[i][left]=-1;
                }
            }
            left++;
        }
        
        return ans;
        
    }
};
