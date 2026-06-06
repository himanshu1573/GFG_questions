class Solution {
  public:
  bool checker(vector<int> &arr, int k,int mid){
      int student=1;int curr_pages=0;
      for(auto a:arr){
          if(curr_pages+a<=mid){
              
              curr_pages+=a;
          }else{
              student++;
              curr_pages=a;
              
          }
      }
      return student<=k;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k)return -1;
        int low=*max_element(arr.begin(),arr.end());
        long long  high=accumulate(arr.begin(),arr.end(),0LL);
        
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(checker(arr,k,mid)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};