class Solution {
public:
    bool valid(vector<vector<int>>&grid){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]!=1) return 0;
            }
        }
        return 1;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        if(valid(grid)) return 0;
        int ans = INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                
                
                for(int ai=0;ai<3;ai++){
                    for(int aj=0;aj<3;aj++){
                        if(grid[i][j]==0 && grid[ai][aj]>1){
                            grid[i][j]++;
                            grid[ai][aj]--;
                            ans = min(ans ,  abs(i-ai)+abs(j-aj)+minimumMoves(grid));
                            grid[i][j]--;
                            grid[ai][aj]++;
                        }
                    }
                }
            }
        }
        return ans ;
    }
};