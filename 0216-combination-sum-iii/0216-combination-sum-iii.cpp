class Solution {
public:
    void solve(vector<vector<int>>&res,vector<int>&ds , int k,int n,int st , int end){
        if(n==0){
            if(k==ds.size()){
                res.push_back(ds);
            }
            return;
        }
        for(int i=st;i<=end;i++){
            ds.push_back(i);
            solve(res,ds,k,n-i,i+1,end);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ds;
        solve(res,ds,k,n,1,9);
        return res;
    }
};