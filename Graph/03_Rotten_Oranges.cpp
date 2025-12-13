class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int fresh=0, cur_time=0;
        
        queue<pair<int, int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    fresh++;
                }
                
                if(mat[i][j]==2){
                    q.push({i, j});
                }
            }
        }
        
        vector<vector<int>> v={{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int, int> p=q.front();
                int row=p.first;
                int col=p.second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int n_row=row+v[i][0];
                    int n_col=col+v[i][1];
                    
                    if(n_row<0 || n_row>=m || n_col<0 || n_col>=n || mat[n_row][n_col]!=1){
                        continue;
                    }
                    
                    mat[n_row][n_col]=2;
                    q.push({n_row, n_col});
                    fresh--;
                }
            }
            cur_time++;
        }
        
        if(fresh==0) return cur_time;
        return -1;
        
    }
};
