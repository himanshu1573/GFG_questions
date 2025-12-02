class Solution {
  public:
  vector<vector<vector<int>>> dp;

    int solve(int index, int k, int canBuy, vector<int>& prices) {
        // Base Case 1: No more days left
        if (index == prices.size()) return 0;
        
        // Base Case 2: No more transactions allowed
        if (k == 0) return 0;

        // Check Memoization
        if (dp[index][k][canBuy] != -1) return dp[index][k][canBuy];

        int profit = 0;

        if (canBuy == 1) { 
            // We can buy stock
            // Option A: Buy (Pay price, move to next day, change state to 'cannot buy', k remains same)
            int buy_it = -prices[index] + solve(index + 1, k, 0, prices);
            
            // Option B: Skip (Do nothing, move to next day, state remains 'can buy')
            int skip_it = solve(index + 1, k, 1, prices);
            
            profit = max(buy_it, skip_it);
        }else { 
            // We are holding stock (canBuy == 0)
            // Option A: Sell (Gain price, move to next day, state becomes 'can buy', DECREMENT K)
            int sell_it = prices[index] + solve(index + 1, k - 1, 1, prices);
            
            // Option B: Skip (Keep holding)
            int skip_it = solve(index + 1, k, 0, prices);
            
            profit = max(sell_it, skip_it);
        }

        return dp[index][k][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        
        // Initialize 3D DP: 
        // Size: n x (k+1) x 2
        // We use k+1 because we need index 'k' to exist
        dp.resize(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        // Start recursion: Day 0, k transactions allowed, 1 (true) means we can buy
        return solve(0, k, 1, prices);
        
    }
};
    // 3D DP table: [Day][Transactions Remaining][Can Buy?]
