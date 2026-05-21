class Solution {
public:
    int f(int i,int n,vector<int>&dp,vector<int>& cost)
    {
        if(i==n-1)return cost[i];
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int one=0,two=0;
        if(i+2<=n)two=cost[i]+f(i+2,n,dp,cost);
        one=cost[i]+f(i+1,n,dp,cost);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int a=f(0,n,dp,cost);
        vector<int>dp1(n+1,-1);
        int b=f(1,n,dp1,cost);
        return min(a,b);
    }
};




// class Solution {
// public:
    
//     int climbStairs(int n) {
        
//     }
// };
