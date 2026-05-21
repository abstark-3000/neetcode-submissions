class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int la,lb,ans=0;
        for(int i=0;i<in.size();i++)
        {
            if(i==0)
            {
                la=in[i][0],lb=in[i][1];
            }
            else
            {
                if(in[i][0]==la)
                {
                    ans++;
                    if(lb>=in[i][1])lb=in[i][1];
                }
                else if(in[i][0]>la && in[i][0]<lb)
                {
                    ans++;
                    if(lb>=in[i][1])
                    {
                        la=in[i][0];
                        lb=in[i][1];
                    }
                }
                else 
                {
                    la=in[i][0],lb=in[i][1];
                }
            }
        }
        return ans;
    }
};
