
class Solution {
  public:
    int maxLength(string& s) {
        int n=s.size();
        stack<int> st;
        st.push(-1);
        
        int res=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    res=max(res, i-st.top());
                }
            }
        }
        
        return res;
        
    }
};
