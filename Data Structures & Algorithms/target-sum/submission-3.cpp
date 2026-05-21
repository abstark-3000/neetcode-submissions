class Solution {
public:
    int f(int i,int tar,int curr,vector<int>&nums,vector<vector<int>>&dp,int &su)
    {
        if(i==nums.size())
        {
            if(curr!=tar)return 0;
            return 1;
        }
        if(dp[i][curr+su]!=-1)return dp[i][curr+su];
        int sum=0,sub=0;
        sum=f(i+1,tar,curr+nums[i],nums,dp,su);
        sub=f(i+1,tar,curr-nums[i],nums,dp,su);
        return dp[i][curr+su]= sum+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*sum+1,-1));
        return f(0,target,0,nums,dp,sum);
    }
};
