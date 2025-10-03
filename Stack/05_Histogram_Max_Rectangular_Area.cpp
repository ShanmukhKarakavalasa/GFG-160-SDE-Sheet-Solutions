class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n=arr.size();
        vector<int> res1(n);
        vector<int> res2(n);
        
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                res1[i]=st.top();
            }
            else{
                res1[i]=n;
            }
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                res2[i]=st.top();
            }
            else{
                res2[i]=-1;
            }
            
            st.push(i);
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int prod=(res1[i]-res2[i]-1) * (arr[i]);
            ans=max(ans, prod);
        }
        
        return ans;
        
    }
};
