class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int cnt2=0,cnt1=0,cnt0=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==2)cnt2++;
            else if(arr[i]==1)cnt1++;
        }
        cnt0=arr.size()-(cnt2+cnt1);
        for(int i=0;i<arr.size();i++){
            if(cnt0!=0){
                arr[i]=0;
                cnt0--;
                
            }else if(cnt1!=0){
                arr[i]=1;
                cnt1--;
            }else{
                arr[i]=2;
                
            }
        }

    }
};