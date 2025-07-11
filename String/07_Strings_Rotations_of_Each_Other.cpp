class Solution {
  public:
    void makeLPS(string &pat, vector<int>& lps){
        int len=0;
        int m=pat.size();
        
        lps[0]=0;
        int i=1;
        
        while(i<m){
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
    
    bool areRotations(string &s1, string &s2) {
        s1=s1+s1;
        int m=s1.size();
        int n=s2.size();
        
        vector<int> lps(n,0);
        
        makeLPS(s2, lps);
        
        int i=0, j=0;
        
        while(i<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
                
                if(j==n){
                    return true;
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
        
        return false;
        
    }
};
