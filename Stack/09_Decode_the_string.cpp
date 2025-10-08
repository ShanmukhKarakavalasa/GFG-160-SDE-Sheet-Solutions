
class Solution {
  public:
    string decodedString(string &s) {
        string ans="";
        string num="";
        string emptyString;
        int freq;
        int flag=0;
        
        stack<string> stringStack;
        stack<int> freqStack;
        
        int n=s.size();
        int i=0;
        while(i<n){
            while(i<n && isdigit(s[i])){
                num+=s[i];
                i++;
                flag=1;
            }
            if(num.size()==1) freq=num[0]-'0';
            else{
                stringstream ss(num);
                ss>>freq;
            }
            
            if(flag==1){
                freqStack.push(freq);
                num="";
                flag=0;
            }
            
            if(isalpha(s[i])){
                stringStack.push(emptyString+s[i]);
            }
            
            if(s[i]=='['){
                stringStack.push(emptyString+s[i]);
            }
            
            if(s[i]==']'){
                ans="";
                
                int number=freqStack.top();
                freqStack.pop();
                while(stringStack.top()!=emptyString+'['){
                    ans=stringStack.top()+ans;
                    stringStack.pop();
                }
                
                string temp=ans;
                number--;
                while(number--){
                    ans=temp+ans;
                }
                
                stringStack.pop();
                stringStack.push(ans);
            }
            
            i++;
        }
        
        stringStack.pop();
        while(!stringStack.empty()){
            ans=stringStack.top()+ans;
            stringStack.pop();
        }
        return ans;
        
    }
};
