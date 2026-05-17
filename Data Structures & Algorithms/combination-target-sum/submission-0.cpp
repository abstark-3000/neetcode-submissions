class Solution {
public:
    void f(int i,vector<int>&nums,int t,set<vector<int>>&st,vector<int>temp)
    {
        // if(t<0)return;
        if(i>=nums.size())return;
        if(t==0)
        {
            st.insert(temp);
            return;
        }
        f(i+1,nums,t,st,temp);
        if(t>=nums[i])
        {
            temp.push_back(nums[i]);
            f(i,nums,t-nums[i],st,temp);
            f(i+1,nums,t-nums[i],st,temp);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        set<vector<int>>st;
        f(0,nums,target,st,temp);    
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
