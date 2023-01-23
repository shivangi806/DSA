class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int c=0;
        int x = trust.size();
        if(x==1) return trust[0][1];
        vector<int> indegree(n+1);
        vector<int> outdegree(n+1);
        for(int i=0;i<x;i++){
             indegree[trust[i][1]]++;
             outdegree[trust[i][0]]++;
        }
       for(int i=1;i<=n;i++){
           if(indegree[i]==n-1 && outdegree[i]==0){
             return i;
           }
       }
        return -1;
    }
};

// 4
// [[1,3],[1,4],[2,3],[2,4],[4,3]]