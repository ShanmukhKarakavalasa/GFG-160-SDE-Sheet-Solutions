class Solution {
  public:
    bool wordUtil(int i, int j, int ind, vector<vector<char>>& mat,
    string& word, int m, int n, vector<vector<bool>> &vis){
        if(ind==word.size()){
            return true;
        }
        
        if(i<0 || i>=m || j<0 || j>=n) return false;
        
        if(mat[i][j]==word[ind] && vis[i][j]==false){
            vis[i][j]=true;
            bool res=(wordUtil(i-1, j, ind+1, mat, word, m, n, vis) ||
                    wordUtil(i+1, j, ind+1, mat, word, m, n, vis) ||
                    wordUtil(i, j-1, ind+1, mat, word, m, n, vis) ||
                    wordUtil(i, j+1, ind+1, mat, word, m, n, vis));
            vis[i][j]=false;
            
            return res;
        }
        
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                if(wordUtil(i, j, 0, mat, word, m, n, vis)){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};
