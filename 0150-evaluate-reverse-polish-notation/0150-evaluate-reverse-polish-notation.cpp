class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        int n = s.size();
        for(int i=0;i<n;i++){
           if(s[i]=="+" || s[i]=="-" || s[i]=="*" || s[i]=="/"){
               int num2 = st.top();st.pop();
               int num1 = st.top();st.pop();
               if(s[i]=="+") st.push(num1+num2);
               if(s[i]=="-") st.push(num1-num2);
               if(s[i]=="*") st.push(num1*num2);
               if(s[i]=="/") st.push(num1/num2);
           }
            else{
               st.push(stoi(s[i]));
            }
        }
        
        return st.top();
    }
};