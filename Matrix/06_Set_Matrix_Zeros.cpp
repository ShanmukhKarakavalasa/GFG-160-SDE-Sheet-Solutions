class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        vector<int> row;
        vector<int> col;
        int m=mat.size(), n=mat[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        for(int i=0;i<row.size();i++){
            for(int j=0;j<n;j++){
                if(mat[row[i]][j]!=0)   mat[row[i]][j]=0;
            }
        }
        
        for(int i=0;i<col.size();i++){
            for(int j=0;j<m;j++){
                if(mat[j][col[i]]!=0)   mat[j][col[i]]=0;
            }
        }
        
    }
};
