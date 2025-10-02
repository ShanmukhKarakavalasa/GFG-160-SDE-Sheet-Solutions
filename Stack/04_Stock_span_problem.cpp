class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        vector<int> res(n);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                st.pop();
            }
            
            if(!st.empty()){
                res[i]=i-st.top();
            }
            else{
                res[i]=i+1;
            }
            
            st.push(i);
        }
        
        return res;
    }
};
