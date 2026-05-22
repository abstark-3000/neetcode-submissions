class Solution {
public:
    bool f(int i,vector<int>&nums)
    {
        if(i==nums.size()-1)return true;
        if(i>=nums.size())return false;
        bool poss=false;
        for(int x=1;x<=nums[i];x++)
        {
            poss=f(i+x,nums);
            if(poss==true)break;
        }
        return poss;
    }
    bool canJump(vector<int>& nums) {
        return f(0,nums);
    }
};
