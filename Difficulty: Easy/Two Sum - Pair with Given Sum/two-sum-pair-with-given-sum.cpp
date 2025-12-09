class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code her
        //here x+y=target;so x=target-y;
        
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            int x=target-arr[i];
            if(mp.find(x)!=mp.end()){
                return true;
            }else{
                mp.insert({arr[i],x});
            }
        }
        return false;
    }
};