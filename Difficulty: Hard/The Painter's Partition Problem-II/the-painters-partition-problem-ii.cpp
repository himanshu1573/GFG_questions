class Solution {
  public:
  bool checker(vector<int>& arr, int k,int mid){
      int partition=1;
      int curr_sum=0;
      for(auto a:arr){
          if(curr_sum+a<=mid){
              curr_sum+=a;
          }else{
              partition++;
              curr_sum=a;
          }
      }
      return partition<=k;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        int low=*max_element(arr.begin(),arr.end());
        long long high=accumulate(arr.begin(),arr.end(),0LL);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(checker(arr,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
               low=mid+1; 
            }
        }
        return ans;
    }
};