class Solution {
  public:
    int myAtoi(char *s) {
        long long int sign=1, index=0, res=0;
        while(s[index]==' '){
            index++;
        }
        
        if(s[index]=='+' || s[index]=='-'){
            if(s[index++]=='-'){
                sign=-1;
            }
        }
        
        while(s[index]>='0' && s[index]<='9'){
            res=10*res +(s[index++]-'0');
        }
        
        if(sign*res>2147483647 ) return 2147483647;
        else if(sign*res<-2147483648 ) return -2147483648;
        return sign * res;
    }
};
