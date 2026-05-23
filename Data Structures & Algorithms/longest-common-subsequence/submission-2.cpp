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
    int longestCommonSubsequence(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
        // return f(0,0,t1,t2,dp);

        // for(int i=0;i<s.size();i++)if(s[i]==t[t.size()-1])dp[i][t.size()-1]=1;
        // for(int i=0;i<t.size();i++)if(t[i]==s[s.size()-1])dp[s.size()-1][i]=1;


        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=t.size()-1;j>=0;j--)
            {
                int b=0,fi=0,se=0;
                if(s[i]==t[j])b=1+dp[i+1][j+1];
                else
                {
                    fi=dp[i+1][j];
                    se=dp[i][j+1];
                }
                dp[i][j]= max(b,max(fi,se));
            }
        }
        return dp[0][0];
    }
};
