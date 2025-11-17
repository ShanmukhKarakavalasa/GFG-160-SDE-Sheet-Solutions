class Solution {
  public:
    int countPS(string &s) {
        int n=s.size();
        int str_len=0;
        int count=0;
        
        for(int i=0;i<n;i++){
            int left=i, right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                str_len=right-left+1;
                if(str_len>1){
                    count++;
                }
                
                left--;
                right++;
            }
            
            left=i;
            right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                str_len=right-left+1;
                if(str_len>1){
                    count++;
                }
                
                left--;
                right++;
            }
        }
        
        return count;
        
    }
};
