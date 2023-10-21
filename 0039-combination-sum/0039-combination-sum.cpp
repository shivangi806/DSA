class Solution {
public:
    
    void solve(int i ,vector<int>&ds,set<vector<int>>&st ,vector<int>&arr, int tg){
        if(i==arr.size()){
            if(tg==0){
                st.insert(ds);
            }
            return ;
        }
        
        if(tg==0){
            st.insert(ds);
        }
        if(tg-arr[i]>=0){
            ds.push_back(arr[i]);
            solve(i,ds,st,arr,tg-arr[i]);
            ds.pop_back(); 
        }
        
        solve(i+1,ds,st,arr,tg);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tg) {
        vector<int> ds;
        vector<vector<int>> ans;
        set<vector<int>> st;
        solve(0,ds,st,arr,tg);
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};