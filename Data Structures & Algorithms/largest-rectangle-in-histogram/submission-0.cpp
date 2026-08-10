class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>prev(n,0),next(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(st.size()>0 && h[st.top()]>=h[i])st.pop();
            if(st.size()>0)prev[i]=st.top();
            else prev[i]=-1;
            st.push(i);
        }
        while(st.size()>0)st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()>0 && h[st.top()]>=h[i])st.pop();
            if(st.size()>0)next[i]=st.top();
            else next[i]=n;
            st.push(i);
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,abs(-prev[i]+next[i]-1)*h[i]);
        }
        return ans;
    }
};
