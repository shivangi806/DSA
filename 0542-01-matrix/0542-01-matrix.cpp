class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        
        int dx[4]  = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    ans[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int step = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            step++;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = dx[i]+x;
                int ny = dy[i]+y;
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==1 && vis[nx][ny]==0){
                    ans[nx][ny]=step;
                    q.push({step,{nx,ny}});
                    vis[nx][ny]=1;
                }
            }
        }
        return ans;
    }
};