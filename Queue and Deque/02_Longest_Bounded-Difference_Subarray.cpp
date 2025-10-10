class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {\
        vector<int> res;
        
        deque<int> minQueue, maxQueue;
        int n=arr.size();
        int left=0, right=0;
        int finalStart=0, finalEnd=0;
        
        while(right<n){
            while(!minQueue.empty() && arr[minQueue.back()]>arr[right]){
                minQueue.pop_back();
            }
            
            while(!maxQueue.empty() && arr[maxQueue.back()]<arr[right]){
                maxQueue.pop_back();
            }
            
            minQueue.push_back(right);
            maxQueue.push_back(right);
            
            while(arr[maxQueue.front()] - arr[minQueue.front()] > x){
                if(left==minQueue.front()){
                    minQueue.pop_front();
                }
                if(left==maxQueue.front()){
                    maxQueue.pop_front();
                }
                
                left++;
            }
            
            if(right - left > finalEnd - finalStart){
                finalEnd=right;
                finalStart=left;
            }
            
            right++;
        }
        
        for(int i=finalStart;i<finalEnd+1;i++){
            res.push_back(arr[i]);
        }
        
        return res;
        
    }
};
