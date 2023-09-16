class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& hg) {
        int n = hg.size();
        int m = hg[0].size();

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>  , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int diff=0;
        int dx[4] = {0,0,1,-1};
        int dy[4]= {1,-1,0,0};
        while(!pq.empty()){
            diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(hg[x][y]==-1) continue;
            if(x==n-1 && y==m-1) return diff;
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && hg[nx][ny]!=-1){
                    int maxi = max(diff , abs(hg[nx][ny]-hg[x][y]));
                    pq.push({maxi , {nx,ny}});
                    // hg[nx][ny]=-1;
                }
            }
            hg[x][y]=-1;
        }
        return -1;
    }
};