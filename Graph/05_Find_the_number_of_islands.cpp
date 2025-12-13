class Solution {
  public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, 
    int i, int j, int m, int n){
        vis[i][j]=true;
        
        vector<vector<int>> v={{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1}};
        for(int k=0;k<8;k++){
            int row=i+v[k][0];
            int col=j+v[k][1];
            
            if(row>=0 && row<m && col>=0 && col<n && 
              !vis[row][col] && grid[row][col]=='L'){
                   dfs(grid, vis, row, col, m, n);
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='L'){
                    dfs(grid, vis, i, j, m, n);
                    count++;
                }
            }
        }
        
        return count;
        
    }
};
