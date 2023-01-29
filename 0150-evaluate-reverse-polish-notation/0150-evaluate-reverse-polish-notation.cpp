class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> st;
        int n = t.size();
        for(int i=0;i<n;i++){
            if(t[i]!="+" && t[i]!="-" && t[i]!="*" && t[i]!="/"){
                st.push(stoi(t[i]));
            }
            else{
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                if(t[i]=="+") st.push(n1+n2);
                if(t[i]=="-") st.push(n2-n1);
                if(t[i]=="*") st.push(n1*n2);
                if(t[i]=="/") st.push(n2/n1);
            }
        }
        return st.top();
    }
};