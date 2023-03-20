class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        //  values ko uske grid(i , j) ke sath map karenge
        int n = grid.size();
        
        if(grid[0][0]!=0) return 0;
        
        vector<vector<int>> mp(n*n , vector<int>(2));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
             mp[grid[i][j]][0] =  i;
             mp[grid[i][j]][1] =  j ;    
            }
        }
        
        // 2 coordinate ka x coordinate ka diff = a 
        // y coordinate ka diff = b
        // do coordinate k ebicih ka distance = a + b 
        // for the move to be valid dist shd be 3 nd no one out of a nd be shud be 3 
        for(int i=1;i<n*n;i++){
            int a = abs (mp[i-1][0] - mp[i][0]) ;  // x coordinate
            int b =abs(mp[i-1][1] - mp[i][1]) ;  // y coordinate
            int dist = a+b;
            
            if(dist!=3  || (a==3 || b==3)) return 0;
            
        }
        return 1;
    }
};