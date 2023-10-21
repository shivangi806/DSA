class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        int n = it.size();
        sort(it.begin(),it.end());
        vector<vector<int>> ans;
        ans.push_back(it[0]);
        for(int i=1;i<n;i++){
            if(ans.back()[1]>=it[i][0]){
                // merge
                ans.back()[1] = max(ans.back()[1] , it[i][1]);
            }
            else{
                ans.push_back(it[i]);
            }
        }
        return ans;
    }
};