class Solution {
public:
    void solve(int i,  vector<string> &ans,string &temp , string&digits,map<char,string>&m){
        if(i==digits.size()){
            ans.push_back(temp);
            return ;
        }
        string str = m[digits[i]];
        
        for(int j=0;j<str.size();j++){
            temp.push_back(str[j]);
            solve(i+1,ans,temp,digits,m);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char  , string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        
        vector<string> ans;
        if(digits.size()==0) return ans;
        string temp;
        solve(0,ans,temp,digits,m);
        return ans;
    }
};