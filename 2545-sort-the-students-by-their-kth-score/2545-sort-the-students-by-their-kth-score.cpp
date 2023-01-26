class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& a, int k) {
        vector<pair<int,int>> v;
        int n = a.size();
        int m = a[0].size();
        for(int i=0;i<n;i++){
            v.push_back({a[i][k] , i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        vector<vector<int>> res(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int x= v[i].second;
            for(int j=0;j<m;j++){
              res[i][j]=a[x][j];
            }
            
        }
        return res;
    }
};