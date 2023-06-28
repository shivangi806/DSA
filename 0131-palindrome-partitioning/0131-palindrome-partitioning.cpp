class Solution {
public:
    
    int dp[20];
    int n ;
    bool pal(string &s , int i , int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    void solve(string &s , vector<string>&ds , vector<vector<string>>&res , int i){
        if(i>=s.size()){
            res.push_back(ds);
            return ;
        }
        for(int k=i;k<n;k++){
            if(pal(s,i,k)){
                ds.push_back(s.substr(i ,k-i+1));
                solve(s , ds , res, k+1);
                ds.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<string> ds;
        vector<vector<string>> res;
        solve(s , ds , res ,0);
        return res ;
    }
};