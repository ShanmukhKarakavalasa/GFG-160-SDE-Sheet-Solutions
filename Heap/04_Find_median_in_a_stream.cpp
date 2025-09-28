class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> res;
        priority_queue<int> leftMaxHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;
        
        for(int i=0;i<arr.size();i++){
            leftMaxHeap.push(arr[i]);
            
            int ele=leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(ele);
            
            if(rightMinHeap.size() > leftMaxHeap.size()){
                int ele=rightMinHeap.top();
                rightMinHeap.pop();
                leftMaxHeap.push(ele);
            }
            
            double median;
            if(leftMaxHeap.size()!=rightMinHeap.size()){
                median=leftMaxHeap.top();
            }
            else{
                median=(double) (leftMaxHeap.top() + rightMinHeap.top())/2;
            }
            
            res.push_back(median);
        }
        
        return res;
        
    }
};
