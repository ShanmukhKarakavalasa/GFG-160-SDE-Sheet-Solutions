class Solution {
  public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> aux(arr.begin(), arr.end());
        
        for(int i=0;i<n;i++){
            arr[i]=aux[(i+d)%n];
        }       
        
    }
};
