class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
     int prefixSum=0;
     int count=0;
     
     unordered_map<int, int> mp;
     for(int i=0; i<arr.size(); i++){
         prefixSum+= arr[i];
         if(mp.find(target-arr[i])!=mp.end()){
             count= count+ mp[target-arr[i]];
         }
         mp[arr[i]]++;
         
     }
     return count;
    }
};

