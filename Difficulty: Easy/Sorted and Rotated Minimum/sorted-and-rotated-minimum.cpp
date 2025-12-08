class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            // If mid is greater than the last element, the min is in the right half
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return arr[low];
    }
};