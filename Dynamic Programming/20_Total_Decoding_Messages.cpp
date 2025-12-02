class Solution {
  public:
    int countWays(string &digits) {
        int n=digits.size();
        vector<int> dp(n+1, 0);
        dp[0]=1;
        
        if(digits[0]=='0'){
            dp[1]=0;
        }
        else{
            dp[1]=1;
        }
        
        for(int i=2;i<=n;i++){
            int one_digit=digits[i-1]-'0';
            int two_digit=stoi(digits.substr(i-2, 2));
            
            if(one_digit!=0){
                dp[i]+=dp[i-1];
            }
            
            if(two_digit>=10 && two_digit<=26){
                dp[i]+=dp[i-2];
            }
        }
        
        return dp[n];
        
    }
};
