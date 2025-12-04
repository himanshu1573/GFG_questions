class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int MOD = 1e9 + 7; 
        // dp[i][j] stores the number of ways to get sum 'j' using first 'i' elements
        // Initialized to 0 by default
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        // Base Case: There is 1 way to make sum 0 (by choosing the empty set)
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int currentVal = arr[i-1]; // 
                // Option 1: Exclude current item (copy value from previous row)
                dp[i][j] = dp[i-1][j];
                // Option 2: Include current item (if it fits in the current sum)
                if (j >= currentVal) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j - currentVal]) % MOD;
                }
            }
        }
        return dp[n][target];
    }
};