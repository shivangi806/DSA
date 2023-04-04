class Solution {
public:
    int partitionString(string s) {
    int i=0, j=0;
    int c=0;
    unordered_map<char,int>m;
    int n = s.size();
    while(j<n)
    {
        m[s[j]]++;
        if(m[s[j]]>1)
        {
            c++;
            while(j!=i)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }c++;
    return c;
    }
};