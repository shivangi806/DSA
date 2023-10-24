class Solution {
public:
//     void solve(int i, string &digits, string &ds, vector<string>& ans, map<char, string>& mp) {
//         if (i == digits.size()) {
//             ans.push_back(ds);
//             return;
//         }

//         string tmp = mp[digits[i]];
//         for (int k = 0; k < tmp.size(); k++) {
//             ds.push_back(tmp[k]);
//             solve(i + 1, digits, ds, ans, mp);
//             ds.pop_back();
//         }
//     }
    
    void solve(int i , string &dg,string &ds, vector<string>&ans,map<char, string> &mp){
        if(i==dg.size()){
            ans.push_back(ds);
            return;
        }
        
        string tmp = mp[dg[i]];
        for(int k=0;k<tmp.size();k++){
            ds.push_back(tmp[k]);
            solve(i+1,dg,ds,ans,mp);
            ds.pop_back();
        }
        
        
    }
    vector<string> letterCombinations(string digits) {
        map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string ds;
        vector<string> ans;
        if(digits.size()==0) return ans;
        solve(0, digits, ds, ans, mp);
        return ans;
    }
};
