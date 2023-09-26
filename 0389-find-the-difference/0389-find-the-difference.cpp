class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        int m = t.size();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0;
        int j=0;
        while(1){
            if(i<n && j<m && s[i]==t[j]){
                // cout<<i<<" "<<j<<endl;
                i++;
                j++;
            }
            else{
                if(n>m){
                    return s[i];
                }
                else{
                    return t[i];
                }
            }
        }
        if(n>m) return s[0];
        return t[0];
    }
};