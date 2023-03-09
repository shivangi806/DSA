class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string> alpha; // for keeping track of alphabets
        stack<int> number; // for keeping track of numbers
        string res ; // resultant string
        int count = 0; // count of alphabets
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                 count= count*10 + s[i]-'0' ;
            }
            else if(s[i]=='['){
                alpha.push(res);
                number.push(count);
                res="";
                count=0;
            }
            else if(s[i]==']'){
                string temp = res ;
                for(int i=0;i<number.top()-1;i++){
                    res += temp;
                }
                res = alpha.top() + res;
                alpha.pop();
                number.pop();
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res  ;
    }
};