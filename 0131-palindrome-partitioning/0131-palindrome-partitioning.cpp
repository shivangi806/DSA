class Solution {
public:
    bool valid(string  s , int l , int h){
        while(l<=h){
            if(s[l++]!=s[h--]){
                return false;
            }
        }
        return true;
    }
    void recur( vector<vector<string>>&ans , vector<string>&ds , string s , int idx){
        if(idx==s.size()) {
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            if(valid(s,idx,i)){
                ds.push_back(s.substr(idx , i-idx+1));
                recur(ans,ds,s,i+1);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        recur(ans,ds,s,0);
        return ans ;
    }
};