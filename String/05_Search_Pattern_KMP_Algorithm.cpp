
class Solution {
  public:
    void constructlps(string& pat, int n, vector<int>& lps){
        int len=0, i=1;
        lps[0]=0;
        
        while(i<n){
            if(pat[len]==pat[i]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    
    vector<int> search(string& pat, string& txt) {
        int m=txt.size();
        int n=pat.size();
        
        vector<int> lps(n);
        vector<int> ans;
        
        constructlps(pat, n, lps);
        
        int i=0, j=0;
        
        while(i<m){
            if(txt[i]==pat[j]){
                i++;
                j++;
                
                if(j==n){
                    ans.push_back(i-j);
                    j=lps[j-1];
                }
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
        
        return ans;
        
    }
};
