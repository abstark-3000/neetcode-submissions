class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i==nums.size()-1)return 0;
        if(i>=nums.size())return 1e9;
        if(dp[i]!=-1)return dp[i];
        int val=1e9;
        for(int a=1;a<=nums[i];a++)
        {
            int x=f(i+a,nums,dp);
            val=min(val,x);
        }
        return dp[i]= 1+val;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};
