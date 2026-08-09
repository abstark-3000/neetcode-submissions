class Solution {
public:
    int trap(vector<int>& h) {
        vector<int>prev(h.size(),-1);
        vector<int>next(h.size(),-1);
        stack<int>st;
        int i=0;
        while(i<h.size())
        {
            while(st.size()>0 && st.top()<=h[i])st.pop();
            if(st.size()>0)prev[i]=st.top();
            else st.push(h[i]);
            i++;
        }
        while(st.size()>0)st.pop();
        i=h.size()-1;
        while(i>=0)
        {
            while(st.size()>0 && st.top()<=h[i])st.pop();
            if(st.size()>0)next[i]=st.top();
            else st.push(h[i]);
            i--;
        }
        int ans=0;
        for(int i=0;i<h.size();i++)
        {
            if(prev[i]!=-1 && next[i]!=-1)
            {
                ans+=min(prev[i],next[i])-h[i];
            }
        }
        return ans;
    }
};
