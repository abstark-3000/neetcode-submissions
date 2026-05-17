class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({x,{points[i][0],points[i][1]}});
        }
        vector<vector<int>>ans;
        while(k-->0)
        {
            auto it=pq.top();
            pq.pop();
            int a=it.second.first,b=it.second.second;
            ans.push_back({a,b});
        }
        return ans;
    }
};