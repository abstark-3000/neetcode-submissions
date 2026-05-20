class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=0,notpick=0;
        pick=nums[i]+f(i+2,nums,dp);
        notpick=f(i+1,nums,dp);
        return dp[i]= max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        int ans=f(0,nums,dp);
        return ans;
    }
};
