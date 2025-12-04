class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        int n=arr.size();
       if (n == 1) return 0;           // If size is 1, index 0 is the peak
        if (arr[0] > arr[1]) return 0;  // Check first element
        if (arr[n-1] > arr[n-2]) return n-1; // Check last element
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>arr[mid+1]&& arr[mid]>arr[mid-1])return mid;
            else if(arr[mid+1]>arr[mid])low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};