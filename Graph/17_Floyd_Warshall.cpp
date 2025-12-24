class Solution {
  public:
    void floydWarshall(vector<vector<int>>& mat) {
        int n=mat.size();
       
        for(int v=0;v<n;v++){ 
            for(int i=0;i<n;i++){ 
                for(int j=0;j<n;j++){ 
                    if(mat[i][v]!=1e8 && mat[v][j]!=1e8){
                        mat[i][j]= min(mat[i][j], mat[i][v]+mat[v][j]); //v-> vertex via
                    }
                }
            }
        }
    }
};
