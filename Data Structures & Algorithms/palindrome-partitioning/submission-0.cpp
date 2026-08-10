class Solution {
public:
    bool pld(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void f(int i,vector<vector<string>>&ans,string &s,vector<string>&temp)
    {
        if(i==s.size())
        {
            ans.push_back(temp);
            return;
        }
        string x="";
        for(int j=i;j<s.size();j++)
        {
            x+=s[j];
            if(pld(x)){
                temp.push_back(x);
                f(j+1,ans,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        // string x="";
        vector<string>temp;
        f(0,ans,s,temp);
        return ans;
    }
};
