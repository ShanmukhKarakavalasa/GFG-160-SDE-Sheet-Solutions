class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zeros=0, ones=0, twos=0;
        
        for(auto i: arr){
            if(i==0) zeros++;
            else if(i==1) ones++;
            else twos++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(zeros>0){
                arr[i]=0;
                zeros--;
                continue;
            } 
            else if(ones>0){
                arr[i]=1;
                ones--;
                continue;
            } 
            else if(twos>0){
                arr[i]=2;
                twos--;
                continue;
            } 
        }        
        
    }
};
