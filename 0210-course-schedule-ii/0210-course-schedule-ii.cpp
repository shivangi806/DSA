class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for (auto it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adj[v].push_back(u);
        }
        
        
        queue<int> q;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans ;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==n) return ans ;
        return {};
    }
};



// class Solution {
// public:
//     void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
//         vis[node] = 1;
//         for (auto it : adj[node]) {
//             if (!vis[it]) {
//                 dfs(it, adj, vis, st);
//             }
//         }
//         st.push(node);
//     }

//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> adj[numCourses];
//         for (auto it : prerequisites) {
//             int u = it[1];
//             int v = it[0];
//             adj[v].push_back(u);
//         }
//         vector<int> vis(numCourses, 0);
//         stack<int> st;
//         for (int i = 0; i < numCourses; i++) {
//             if (!vis[i]) {
//                 dfs(i, adj, vis, st);
//             }
//         }
//         vector<int> ans;
//         while (!st.empty()) {
//             ans.push_back(st.top());
//             st.pop();
//         }
//         if (ans.size() == numCourses) {
//             return ans;
//         }
//         return {};
//     }
// };
