class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        map<int, int> mp; 
        stack<int> st; //index, next_greater
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(arr[i]>arr[st.top()]){
                while(!st.empty() && arr[i]>arr[st.top()]){
                    mp[st.top()]=arr[i];
                    st.pop();
                }
                
                st.push(i);
            }
            else{
                st.push(i);
            }
        }
        
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        
        for(int i=0;i<n;i++){
            ans.push_back(mp[i]);
        }
        
        return ans;
    }
};
