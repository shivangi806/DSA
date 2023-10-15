class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n-2;i++){
            int f=0;
            set<char> st;
            for(int j=i;j<i+3;j++){
                if(st.find(s[j])!=st.end()){
                    f=1;
                    break;
                }
                st.insert(s[j]);
            }
            if(f==0) ans++;
        }
        return ans;
    }
};