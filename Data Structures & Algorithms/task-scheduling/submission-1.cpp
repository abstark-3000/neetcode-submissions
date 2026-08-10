class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<tuple<int,int>>q;
        priority_queue<int>pq;
        unordered_map<char,int>m;
        for(int i=0;i<tasks.size();i++)m[tasks[i]]++;
        for(auto it:m)pq.push(it.second);
        int time=0;
        while(pq.size()!=0 || q.size()!=0)
        {
            if(pq.size()>0)
            {
                auto it=pq.top();
                if(it-1>0)q.push({time,it-1});
                pq.pop();
                time++;
            }else time++;
            while(q.size()>0)
            {
                auto [t,rem]=q.front();
                if(time>n+t)
                {
                    pq.push(rem);
                    q.pop();
                }else break;
            }
        }
        return time;
    }
};
