class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n=arr.size();
        int sum= accumulate(arr.begin(), arr.end(), 0);
        if(sum%2!=0) return false;
        
        int target=sum/2;
        set<int> st;
        st.insert(0);
        for(int i=0;i<n;i++){
            set<int> sub_set;
            for(auto e:st){
                if(e+arr[i]==target) return true;
                sub_set.insert(e+arr[i]);
                sub_set.insert(e);
            }
            
            st=sub_set;
        }
        
        return false;
        
    }
};
