class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> adj(n);
        for(int i = 0; i < n; i++){
            adj[edges[i]] += i;
        }
        long long mx = INT_MIN;
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(adj[i] > mx){
                mx = adj[i];
                idx = i;
            }
        }
        return idx;
    }
};