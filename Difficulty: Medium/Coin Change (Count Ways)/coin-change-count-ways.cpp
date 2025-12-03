class Solution {
public:
    long long int count(vector<int>& coins, int sum) {
        vector<long long int> dp(sum+1, 0);
        dp[0] = 1;
        for(int j=0; j<coins.size(); j++) {
            for(int i=coins[j]; i<=sum; i++) {
                dp[i] += dp[i-coins[j]];
            }
        }
        return dp[sum];
    }
};