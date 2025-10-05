
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> v1(n);
        vector<int> v2(n);
        vector<int> res(n, 0);
        
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                v2[i]=st.top();
            }
            else{
                v2[i]=n;
            }
            
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                v1[i]=st.top();
            }
            else{
                v1[i]=-1;
            }
            
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            int len=v2[i]-v1[i]-1;
            res[len-1]=max(res[len-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            res[i]=max(res[i], res[i+1]);
        }
        
        return res;
        
    }
};
