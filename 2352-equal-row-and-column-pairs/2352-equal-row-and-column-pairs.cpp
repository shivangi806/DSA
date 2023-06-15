class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        multiset<string> ms1, ms2;
        for(int i=0;i<grid.size();i++){
            string rows , cols;
            for(int j=0;j<grid[0].size();j++){
                rows = rows + " " + to_string(grid[i][j]);
                cols=cols+" "+to_string(grid[j][i]);
            }
            ms1.insert(rows);
            ms2.insert(cols);
        }
        int c=0;
        for(auto it : ms1){
            c+=ms2.count(it);
        }
        return c;
    }
};