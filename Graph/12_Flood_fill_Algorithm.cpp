class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& res, vector<vector<int>>& image,
    vector<int>& row_cor, vector<int>& col_cor, int newColor, int init_color){
        res[row][col]= newColor;
        int m=res.size();
        int n=res[0].size();
        
        for(int i=0;i<4;i++){
            int nrow= row+ row_cor[i];
            int ncol= col+ col_cor[i];
            
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==init_color
             && res[nrow][ncol]!=newColor){
                 dfs(nrow, ncol, res, image, row_cor, col_cor, newColor, init_color);
             }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int init_color=image[sr][sc];
        vector<vector<int>> res=image;
        
        vector<int> row_cor={1, 0, -1, 0};
        vector<int> col_cor={0, 1, 0, -1};
        
        dfs(sr, sc, res, image, row_cor, col_cor, newColor, init_color);
        
        return res;
    }
};
