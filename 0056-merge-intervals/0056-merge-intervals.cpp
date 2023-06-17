class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intr) {
        vector<vector<int>> ans ;
        int i;
        int n = intr.size();
        sort(intr.begin(),intr.end());
        vector<int> ds;
        ds = intr[0];
        for(i=1;i<intr.size();i++){
             if(ds[1] >= intr[i][0]){
                 ds[1]=max(ds[1],intr[i][1]);
             }
             else{
                 ans.push_back(ds);
                 ds={intr[i][0],intr[i][1]};
             }
        }
        ans.push_back(ds);
        return ans ;
    }
};