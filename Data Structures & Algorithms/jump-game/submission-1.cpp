class Solution {
public:
    bool f(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i==nums.size()-1)return true;
        if(i>=nums.size())return false;
        if(dp[i]!=-1)return dp[i];
        bool poss=false;
        for(int x=1;x<=nums[i];x++)
        {
            poss=f(i+x,nums,dp);
            if(poss==true)break;
        }
        return dp[i]= poss;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};
