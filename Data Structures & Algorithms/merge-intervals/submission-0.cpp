class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++)
        {
            if(i==0)ans.push_back(intervals[i]);
            else
            {
                int x=ans.size();
                int a=ans[x-1][0],b=ans[x-1][1],m=intervals[i][0],n=intervals[i][1];
                if(m==a)
                {
                    ans[x-1][1]=max(b,n);
                }
                else if(m>a && m<=b)
                {
                    ans[x-1][1]=max(b,n);
                }
                else ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
