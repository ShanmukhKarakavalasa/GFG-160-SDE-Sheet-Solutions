class Solution {
  public:
    void getLPS(string& s, vector<int>& lps){
        int m=s.size();
        lps[0]=0;
        int len=0;
        int i=1;
        
        while(i<m){
            if(s[len]==s[i]){
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
    
    int minChar(string& s) {
        string s2=s;
        int n=s.size();
        reverse(s2.begin(), s2.end());
        s=s+"$"+s2;
        int m=s.size();
        
        vector<int> lps(m, 0);
        getLPS(s, lps);
        
        return n-lps[m-1];
        
    }
};
