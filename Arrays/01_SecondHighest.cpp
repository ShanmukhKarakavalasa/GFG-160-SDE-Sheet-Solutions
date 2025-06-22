#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int highest=INT_MIN, sec_highest;
        
        for(auto i: arr){
            if(i>highest){
                highest=i;
            }
        }
        
        sec_highest=INT_MIN;
        for(auto i: arr){
            if(i>sec_highest && highest>i){
                sec_highest=i;
            }
        }
        
        if(sec_highest==INT_MIN) return -1;
        return sec_highest;
    }
};
