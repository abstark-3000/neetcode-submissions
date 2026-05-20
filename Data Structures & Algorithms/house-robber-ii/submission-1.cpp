class Solution {
public:
    int f(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=0,notpick=0;
        pick=nums[i]+f(i+2,n,nums,dp);
        notpick=f(i+1,n,nums,dp);
        return dp[i]= max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int first=-1,sec=-1;
        
        int n=nums.size();
        vector<int>dp(n+1,-1);
        first=f(1,n,nums,dp);
        vector<int>dp2(n+1,-1);
        sec=f(0,n-1,nums,dp2);
        return max(first,sec);
    }
};
