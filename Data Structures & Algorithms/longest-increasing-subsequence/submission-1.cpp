class Solution {
public:
    int f(int i,vector<int>&nums,int last,vector<vector<int>>&dp)
    {
        if(i==nums.size())return 0;
        if(last!=-1 && dp[i][last]!=-1)return dp[i][last];
        int pick=0,no=0;
        if(last==-1 || nums[i]>nums[last])
        {
            pick=1+f(i+1,nums,i,dp);
            // no=f(i+1,nums,last);
        }
        no=f(i+1,nums,last,dp);
        if(last==-1)return max(pick,no);
        return dp[i][last]= max(pick,no);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return f(0,nums,-1,dp);
    }
};
