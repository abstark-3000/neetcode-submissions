class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int>m;
        for(int i=0;i<position.size();i++)
        {
            position[i]=target-position[i];
            m[position[i]]=i;
        }
        sort(position.begin(),position.end());
        int ans=0;
        float t=-1.0;
        for(int i=0;i<position.size();i++)
        {
            int curr=speed[m[position[i]]];
            float time=(1.0*position[i]/curr);
            if(t<time)
            {
                ans++;
                t=time;
            }
        }
        return ans;
    }
};
