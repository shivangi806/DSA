class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastIndex(26, -1);
        vector<bool> vis(26, false);
        for(int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        stack<char> st;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(vis[ch - 'a']) continue;
            while(!st.empty() && st.top() > ch && lastIndex[st.top() - 'a'] > i) {
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            vis[ch - 'a'] = true;
        }
        string res;
        while(!st.empty()) {
            res = st.top() + res; 
            st.pop();
        }
        return res;
    }
};
