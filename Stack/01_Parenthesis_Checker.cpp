
class Solution {
  public:
    bool isBalanced(string& k) {
        stack<char> s;
        int n=k.size();
        for(int i=0;i<n;i++){
            if(k[i]=='{' || k[i]=='[' || k[i]=='('){
                s.push(k[i]);
            }
            else{
                if(k[i]=='}' && s.size()>0 && s.top()=='{'){
                    s.pop();
                }
                else if(k[i]==']' && s.size()>0 && s.top()=='['){
                    s.pop();
                }
                else if(k[i]==')' && s.size()>0 && s.top()=='('){
                    s.pop();
                }
                else return false;
            }
        }
        
        if(s.size()==0) return true;
        return false;
        
    }
};
