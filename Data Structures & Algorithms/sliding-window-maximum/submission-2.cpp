class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        int i=0;
        vector<int>ans;
        while(i<nums.size())
        {
            if(i>=k)
            {
                ans.push_back(nums[q.front()]);
            }
            while(q.size()>0 && i-q.front()>=k)q.pop_front();
            while(q.size()>0 && i-q.back()>=k)q.pop_back();

            if(q.size()==0 || nums[q.front()]<=nums[i])
            {
                while(q.size()>0)q.pop_back();
                q.push_front(i);
            }else{
                while(q.size()>0 && nums[q.back()]<=nums[i])q.pop_back();
                q.push_back(i);
            }
            i++;
        }
        ans.push_back(nums[q.front()]);
        return ans;
    }
};
