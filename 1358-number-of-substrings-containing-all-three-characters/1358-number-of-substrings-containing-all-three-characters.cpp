class Solution {
public:
    
    int numberOfSubstrings(string s) {
        int i=0;
        int j=0;
        int n =s.size();
        int ans=0 ;
        map<char,int> m;
        for(int j=0;j<n;j++){
            m[s[j]]++;
            while(m['a'] > 0 && m['b'] > 0 && m['c'] > 0 && i < j){
                m[s[i]]--;
                ans += (n-j);
                i++;
            }
        }
        return ans ;
    }
};