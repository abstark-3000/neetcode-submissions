class Solution {
public:
    int f(int i,vector<int>&coins,int n,vector<vector<int>>&dp)
    {
        if(n==0)return 0;
        if(i==coins.size()-1)
        {
            if(coins[i]>n)return 1e9;
            else if(coins[i]!=0 && n%coins[i]!=0)return 1e9;
            return n/coins[i];
        }
        if(dp[i][n]!=-1)return dp[i][n];
        int pick=1e9,no=1e9;
        if(n>=coins[i])
        {
            pick=min((1+f(i+1,coins,n-coins[i],dp)),(1+f(i,coins,n-coins[i],dp)));
            no=f(i+1,coins,n,dp);
        }
        else no=f(i+1,coins,n,dp);
        return dp[i][n]=min(pick,no);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans= f(0,coins,amount,dp);
        if(ans==1e9)return -1;
        return ans;      
    }
};
