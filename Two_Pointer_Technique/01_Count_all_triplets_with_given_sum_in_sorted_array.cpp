
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n=arr.size();
        int count=0;
        int left=0, right=n-1;
        
        for(int i=0;i<n-2;i++){
            int req_sum=target-arr[i];
            left=i+1, right=n-1;
            while(left<right){
                if(arr[left]+arr[right]==req_sum){
                   int ele1=arr[left], ele2=arr[right];
                   int count1=0, count2=0;
                   
                   while(left<=right && arr[left]==ele1){
                       count1++;
                       left++;
                   }
                   
                   while(left<=right && arr[right]==ele2){
                       count2++;
                       right--;
                   }
                   
                   if(ele1==ele2){
                       count+=(count1*(count1-1))/2; //nC2-choose 2 elements among count1 elements
                   }
                   
                   else{
                       count+=(count1*count2);
                   }
                   
                }
                
                else if(arr[left]+arr[right]<req_sum){
                    left++;
                }
                
                else if(arr[left]+arr[right]>req_sum){
                    right--;
                }
            }
        }
        
        return  count;
        
    }
};
