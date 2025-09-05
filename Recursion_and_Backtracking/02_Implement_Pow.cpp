class Solution {
  public:
    double power(double b, int e) {
        if(e==0) return 1;
        
        else if(e<0){
            return 1/pow(b, -e);
        }
        
        double temp=pow(b, e/2);
        
        if(e%2==0) return temp*temp;
        else return temp*temp*b;
        
    }
};
