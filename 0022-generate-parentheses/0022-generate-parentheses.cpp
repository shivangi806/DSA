class Solution {
public:
    
    void solve(int op , int cl , string &ds , vector<string>&ans){
        if(op<=0 && cl<=0){
            ans.push_back(ds);
            return;
        }
        
        if(op>0){
            ds.push_back('(');
            solve(op-1,cl,ds,ans);
            ds.pop_back();
        }
        
        if(cl>0 && cl>op){
            ds.push_back(')');
            solve(op,cl-1,ds,ans);
            ds.pop_back();
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        string ds;
        solve(n,n,ds,ans);
        return ans ;
    }
};