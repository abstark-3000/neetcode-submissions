class Solution {
public:
    int f(int i,int last,bool buy,vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
        if(i>=prices.size())return 0;
        if(dp[i][last][buy]!=-1)return dp[i][last][buy];
        int take=0,no=0;
        if(buy)
        {
            take=-prices[i]+f(i+1,prices[i],false,prices,dp);
            no=f(i+1,0,true,prices,dp);
        }
        else
        {
            if(prices[i]>=last)take=prices[i]+f(i+2,0,true,prices,dp);
            no=f(i+1,last,false,prices,dp);
        }

        return dp[i][last][buy]= max(take,no);
    }
    int maxProfit(vector<int>& prices) {
        int maxi=-1;
        for(int i=0;i<prices.size();i++)maxi=max(maxi,prices[i]);
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(maxi+1,vector<int>(2,-1)));
        return f(0,0,true,prices,dp);   
    }
};
