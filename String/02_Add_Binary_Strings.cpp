class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string ans="";
        
        int carry=0, first=0, second=0, ones=0;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int m=s1.size(), n=s2.size();
        
        if(m>n){
            int t=m-n;
            while(t--){
                s2+='0';
            }
        }
        else if(n>m){
            int t=n-m;
            while(t--){
                s1+='0';
            }
        }
        
        m=s1.size();
        for(int i=0;i<m;i++){
            ones=0;
            
            if(s1[i]=='1'){
                ones++;
            }
            if(s2[i]=='1'){
                ones++;
            }
            if(carry==1){
                ones++;
            }
            
            if(ones==0){
                carry=0;
                ans+='0';
            }
            else if(ones==1){
                carry=0;
                ans+='1';
            }
            else if(ones==2){
                carry=1;
                ans+='0';
            }
            else if(ones==3){
                carry=1;
                ans+='1';
            }
        }
        if(carry==1){
            ans+='1';
        }
        
        int index=-1;
        reverse(ans.begin(), ans.end());
        for(int i=0; ans[i]=='0';i++){
            index=i;
        }
        if(index!=-1)
        ans.erase(0, index+1);
        
        return ans;
    }
};
