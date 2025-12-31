class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_two=0;
        for(int i: arr){
            xor_two=i ^ xor_two;
        }
        
        xor_two=xor_two & -(xor_two);
        
        vector<int> res(2, 0);
        for(int i: arr){
            if((i & xor_two) ==0){
                res[0]^=i;
            }
            else{
                res[1]^=i;
            }
        }
        
        if(res[0]>res[1]){
            return {res[1], res[0]};
        }
        
        return res;
    }
};
