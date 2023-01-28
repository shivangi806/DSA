class Solution {     
public:
    bool isRectangleCover(vector<vector<int>>& r) {
        map<pair<int,int>,int> m;
        int n =r.size();
        for(int i=0;i<n;i++){
            m[{r[i][0] , r[i][1]}]++;
            m[{r[i][2],r[i][3]}]++;
            m[{r[i][2],r[i][1]}]--;
            m[{r[i][0],r[i][3]}]--;
        }
        int count = 0;
        for(auto it : m){
            count+=abs(it.second);
        }
        if(count==4) return 1;
        return 0;
    }
};