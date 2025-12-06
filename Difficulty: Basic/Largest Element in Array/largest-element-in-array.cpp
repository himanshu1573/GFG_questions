class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxn=-1;
        for(int i=0;i<arr.size();i++){
            maxn=max(maxn,arr[i]);
        }
        return maxn;
    }
};
