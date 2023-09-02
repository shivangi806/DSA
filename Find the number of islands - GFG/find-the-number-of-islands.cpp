//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int n , m ;
    
    void dfs(int i  , int j ,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
        
        grid[i][j]='0';
        // go in 8 direction 
        int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
        int dy[8] = {0, -1, 1, 1, -1, 0, -1, 1};
        
        for(int k=0;k<8;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            dfs(nx,ny,grid);
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    c++;
                    dfs(i,j,grid);
                }
            }
        }
        return c ;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends