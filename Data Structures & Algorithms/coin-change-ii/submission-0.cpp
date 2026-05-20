
class Solution {
public:
    int f(int i,vector<int>&coins,int n,vector<vector<int>>&dp)
    {
        if(n==0)return 1;
        if(i==coins.size()-1)
        {
            if(coins[i]>n)return 0;
            else if(n%coins[i]!=0)return 0;
            return 1;
        }
        if(dp[i][n]!=-1)return dp[i][n];
        int pick=0,no=0;
        if(n>=coins[i])
        {
            pick=(f(i,coins,n-coins[i],dp));
            no=f(i+1,coins,n,dp);
        }
        else no=f(i+1,coins,n,dp);
        return dp[i][n]=pick+no;
    }
    int change(int amount,vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans= f(0,coins,amount,dp);
        return ans;   
    }
};

