class Solution {
public:
    
    void solve(int idx ,vector<int>& nums,vector<int>& ds , vector<vector<int>>&res){
        int n = nums.size();
        if(idx==n){
            res.push_back(ds);
            return ;
        }
        // take that element
        ds.push_back(nums[idx]);
        solve(idx+1 ,nums,ds,res);
        ds.pop_back();
        
        // no take that element
        solve(idx+1 , nums ,ds , res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // ab hame karenge isko recursion se
        vector<vector<int>> res ;
        vector<int> ds;
        solve(0,nums,ds,res);
        return res ;
    }
};