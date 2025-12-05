class Solution {
  public:
  vector<vector<int>>dp;
  int n;
  int solve(int i,int j,vector<vector<int>>& triangle){
      if(i==n)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int down=solve(i+1,j,triangle);
      int diagonal=solve(i+1,j+1,triangle);
      int result=triangle[i][j]+min(down,diagonal);
      dp[i][j]=result;
      return dp[i][j];
      
      
  }
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        n=triangle.size();
        dp.assign(n,vector<int>(n,-1));
        
        int result=solve(0,0,triangle);
        return result;
    }
};