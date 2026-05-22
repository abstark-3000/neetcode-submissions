class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int i=0,j=0,sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            ans=max(ans,sum);
            if(sum<0)
            {
                while(i<=j && sum<0)
                {
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
