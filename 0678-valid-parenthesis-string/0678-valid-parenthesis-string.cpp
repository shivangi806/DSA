class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open,str;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                str.push(i);
            }
            else{
                if(!open.empty()){
                    open.pop();
                }
                else if(!str.empty()){
                    str.pop();
                }
                else return 0;
            }
        }
        while(!open.empty()){
            if(str.empty()) return 0;
            else if(open.top()<str.top()){
                open.pop();
                str.pop();
            }
            else return 0;
        }
        return 1;
    }
};