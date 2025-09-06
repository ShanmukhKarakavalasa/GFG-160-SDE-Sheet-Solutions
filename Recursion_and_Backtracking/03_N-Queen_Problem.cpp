class Solution {
  public:
    void nQueenUtil(int j, int n, vector<bool> &rows, vector<bool> &d1,
    vector<bool> &d2, vector<int> &temp, vector<vector<int>> &res){
        if(j>n){
            res.push_back(temp);
            return;
        }
        
        for(int i=1;i<=n;i++){
            if(!rows[i] && !d1[i-j+n] && !d2[i+j]){
                rows[i]=true;
                d1[i-j+n]=true;
                d2[i+j]=true;
                
                temp.push_back(i);
                
                nQueenUtil(j+1, n, rows, d1, d2, temp, res);
                
                rows[i]=false;
                d1[i-j+n]=false;
                d2[i+j]=false;
                
                temp.pop_back();
            }
        }
                    
    }
    vector<vector<int>> nQueen(int n) {
        vector<bool> rows(n+1, false);
        vector<bool> d1(2*n+1, false);
        vector<bool> d2(2*n+1, false);
        
        vector<int> temp;
        vector<vector<int>> res;
        
        nQueenUtil(1, n, rows, d1, d2, temp, res);
        
        return res;
    }
};
