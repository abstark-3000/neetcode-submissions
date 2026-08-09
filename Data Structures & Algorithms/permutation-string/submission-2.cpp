class Solution {
public:
    bool checkInclusion(string s, string t) {
        if(s.size()>t.size())return false;
        vector<int>m(26,0);
        for(int i=0;i<s.size();i++)m[s[i]-'a']++;
        vector<int>temp(26,0);
        temp=m;
        int i=0,j=0;
        while(j<t.size())
        {
            if(m[t[j]-'a']==0)
            {
                j++;
                i=j;
                temp=m;
                continue;
            }else if(temp[t[j]-'a']==0)
            {
                while(i<=j && temp[t[j]-'a']==0)
                {
                    temp[t[i]-'a']++;
                    i++;
                }
                temp[t[j]-'a']--;
                // i--;
            }else if(temp[t[j]-'a']>0)temp[t[j]-'a']--;
            if(j-i+1==s.size())return true;
            j++;
        }
        return false;
    }
};
