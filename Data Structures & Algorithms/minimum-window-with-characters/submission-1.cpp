class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++)m[t[i]]++;
        int i=0, j=0,len=INT_MAX,idx=-1,cnt=0;
        while(j<s.size())
        {
            m[s[j]]--;
            if(m[s[j]]>=0)cnt++;
            if(cnt==t.size())
            {
                while(cnt==t.size())
                {
                    m[s[i]]++;
                    if(m[s[i]]>0)break;
                    i++;
                }
                if(len>j-i+1)
                {
                    len=j-i+1;
                    idx=i;
                }
                i++;
                cnt--;
            }
            j++;
        }   
        if(idx==-1)return "";
        return s.substr(idx,len);

    }
};
