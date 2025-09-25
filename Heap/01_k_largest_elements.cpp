class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<int> pq(arr.begin(), arr.end());
        vector<int> ans;
        
        while(k--){
            int ele=pq.top();
            ans.push_back(ele);
            pq.pop();
        }
        
        return ans;
    }
};
