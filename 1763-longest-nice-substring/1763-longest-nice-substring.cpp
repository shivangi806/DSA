class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size()<2) return "";
        unordered_set<char> st(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(st.find((char)toupper(s[i]))==st.end() || st.find((char)tolower(s[i]))==st.end()){
                string x = longestNiceSubstring(s.substr(0,i));
                string y = longestNiceSubstring(s.substr(i+1));
                
                if(x.size()>=y.size()) return x;
                return y;
            }
        }
        return s;
    }
};