class Solution {
  public:
    string longestPalindrome(string &s) {
        string res="";
        int len=0;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            int left=i;
            int right=i;
            
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1 > len){
                    len=right-left+1;
                    res=s.substr(left, len);
                }
                
                left--;
                right++;
            }
            
            
            left=i;
            right=i+1;
            
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1 > len){
                    len=right-left+1;
                    res=s.substr(left, len);
                }
                
                left--;
                right++;
            }
        }
        
        return res;
        
    }
};
