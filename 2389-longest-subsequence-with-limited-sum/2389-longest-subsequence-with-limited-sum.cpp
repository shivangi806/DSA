class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        if(nums.empty() || queries.empty()) return {};
        int n=nums.size();
        int m=queries.size();
        vector<int>ans;
        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i++){
           nums[i]+=nums[i-1];
            // cout<<nums[i]<<endl;
        }
        for(int i=0;i<queries.size();i++){
            //upperbouund of queries of  i in nums
            auto it = upper_bound(nums.begin(),nums.end(),queries[i])-nums.begin();
            // cout<<it<<endl;
            it--;
            ans.push_back(it+1);
        }
        return ans;
    }
};