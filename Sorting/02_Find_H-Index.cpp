class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> fq(n+1, 0);
        
        for(int i=0;i<n;i++){
            if(citations[i]>=n){
                fq[n]=fq[n]+1;
            }
            else{
                fq[citations[i]]=fq[citations[i]]+1;
            }
        }
        
        
        int i=n;
        int count=fq[n];
        while(count<i){
            i--;
            count+=fq[i];
        }
        
        return i;
    }
};
