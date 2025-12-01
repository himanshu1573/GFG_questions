#User function Template for python3

class Solution:
    #Function to return list containing first n fibonacci numbers.
    def fibonacciNumbers(self,n):
        # your code here
        dp=[0]*n
        dp[0]=0;
        if n>1:
            dp[1]=1
        for i in range(2,n):
            dp[i]=dp[i-1]+dp[i-2]
            
        return dp