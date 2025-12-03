class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxx=INT_MIN;
        for(int i=0;i<arr.size();i++){
           maxx=max(maxx,arr[i]); 
        }
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
           if(arr[i]!=maxx){
               ans=max(ans,arr[i]);
           } 
        }
        return ans;
    }
};