class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        int nn=t.size(),tmp=-1;
        if(nn==0&&n==1){
            return 1;
        }
        unordered_map<int,int>m,opp;
        for(int i=0;i<nn;i++){
        cout<<i;
            m[t[i][1]]++;
            opp[t[i][0]]++;
            if(m[t[i][1]]==n-1){
                tmp=t[i][1];
            }            
        }
        if(tmp>=0&&opp[tmp]==0){
                    return tmp;
                }
        return -1;
        
        return 0;
       //  int c=0;
       //  int x = trust.size();
       //  if(x==1) return trust[0][1];
       //  vector<int> indegree(n+1);
       //  vector<int> outdegree(n+1);
       //  for(int i=0;i<x;i++){
       //       indegree[trust[i][1]]++;
       //       outdegree[trust[i][0]]++;
       //  }
       // for(int i=1;i<=n;i++){
       //     if(indegree[i]==n-1 && outdegree[i]==0){
       //       return i;
       //     }
       // }
       //  return -1;
    }
};

// 4
// [[1,3],[1,4],[2,3],[2,4],[4,3]]