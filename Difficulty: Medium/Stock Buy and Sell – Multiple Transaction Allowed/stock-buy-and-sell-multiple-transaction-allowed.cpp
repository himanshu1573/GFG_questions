
class Solution {
  public:
  vector<vector<int>>dp;
  int solve(int index,int buy,vector<int>&prices){
      if(index==prices.size())return 0;
      int profit=0;
      if(dp[index][buy]!=-1)return dp[index][buy];
      if(buy){ // buy-1--> indicates that we are currently holding the stock and we can't take the current day stock;
          int skip_it=solve(index+1,1,prices);
          int sell_it= prices[index] + solve(index+1,0,prices);
          profit=max(skip_it,sell_it);
      }else{// buy-0--> indicates that we are currently not hoding the current stock so we can buy it .
          int buy_it= -prices[index] +solve(index+1,1,prices);
          int skip_it=solve(index+1,0,prices);
          profit=max(buy_it,skip_it);
      }
      dp[index][buy]=profit;
      return profit;
  }
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        int ans=solve(0,0,prices);
        return ans;
    }
};