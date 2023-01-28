class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n =s.size();
        for(int i=0;i<n;i++){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]);
            }
            else st.pop();
        }
        string res ;
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            res+=ch;
        }
        reverse(res.begin(),res.end());
        return res ;
    }
};