class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Kadane's Algo
        int mini=nums[0],maxi=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int tmax=max({nums[i],mini*nums[i],maxi*nums[i]});
            int tmin=min({nums[i],mini*nums[i],maxi*nums[i]});
            mini=tmin;
            maxi=tmax;
            ans=max(ans,maxi);
        }
        return ans;
    }
};
