class Solution {
public:
    int f(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(i>=s.size() || j>=t.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int b=0,fi=0,se=0;
        if(s[i]==t[j])b=1+f(i+1,j+1,s,t,dp);
        else
        {
            fi=f(i+1,j,s,t,dp);
            se=f(i,j+1,s,t,dp);
        }
        return dp[i][j]= max(b,max(fi,se));
    }
    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>>dp(t1.size()+1,vector<int>(t2.size()+1,-1));
        return f(0,0,t1,t2,dp);
    }
};
