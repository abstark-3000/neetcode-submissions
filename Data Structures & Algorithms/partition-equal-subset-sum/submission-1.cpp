class Solution {
public:
    bool f(int i,int sum,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==nums.size() && sum!=0)return false;
        if(sum==0)return true;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool take=false,no=false;
        if(sum>=nums[i])take=f(i+1,sum-nums[i],nums,dp);
        no=f(i+1,sum,nums,dp);
        return dp[i][sum]= take || no;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum%2!=0)return false;
        sum/=2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
        return f(0,sum,nums,dp);
    }
};
