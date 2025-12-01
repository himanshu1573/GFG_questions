class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int ans=0;
        int n=arr.size()/2;
        for(auto m:mp){
            if(m.second>n)ans=m.first;
        }
        return ((ans==0)?-1:ans);
    }
};