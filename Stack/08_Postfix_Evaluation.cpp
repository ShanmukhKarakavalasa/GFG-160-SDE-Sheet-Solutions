class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        int n=arr.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(stoi(arr[i]));
            }
            else if(arr[i]=="+" || arr[i]=="-" || arr[i]=="*" || arr[i]=="/"){
                if(st.size()>=2){
                    int b=st.top();
                    st.pop();
                    int a=st.top();
                    st.pop();
                    
                    if(arr[i]=="+"){
                        st.push(a+b);
                    }
                    if(arr[i]=="-"){
                        st.push(a-b);
                    }
                    if(arr[i]=="*"){
                        st.push(a*b);
                    }
                    if(arr[i]=="/"){
                        st.push(a/b);
                    }
                }
            }
            else{
                st.push(stoi(arr[i]));
            }
        }
        
        return st.top();
        
    }
};
