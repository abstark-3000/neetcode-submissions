class Solution {
public:
    void f(int i,set<vector<int>>&st,vector<int>&nums,vector<int>temp)
    {
        if(i>=nums.size())return;
        st.insert(temp);
        f(i+1,st,nums,temp);
        temp.push_back(nums[i]);
        st.insert(temp);
        f(i+1,st,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>temp;
        f(0,st,nums,temp);
        vector<vector<int>>res;
        for(auto it:st)
        {
            res.push_back(it);
        }
        return res;
    }
};
