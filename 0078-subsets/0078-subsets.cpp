class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       // powerset  ka size
        int n = nums.size();
        int ps_size = pow(2,n);
        int eachSetlen = n;
        vector<vector<int>> ans ;
        for(int i=0;i<ps_size;i++){
            vector<int> ds;
            for(int j=0;j<n;j++){
                // agar vo bit set hua
                if(i & (1<<j)){
                    // ds me push kar
                    ds.push_back(nums[j]);
                }
            }
            ans.push_back(ds);
        }
        sort(ans.begin(),ans.end());
        return ans ;
    }
};