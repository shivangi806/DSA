class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<pair<int,int>> pq;
        int n = a.size();
        for(int i=0;i<n;i++){
            pq.push({a[i]+b[i] , i});
        }
        int sum1=0,sum2=0;
        while(!pq.empty()){
            sum1+=a[pq.top().second];
            pq.pop();
            
            if(!pq.empty()){
                 sum2+=b[pq.top().second];
                 pq.pop();   
            }
        }
        if(sum1>sum2) return 1;
        else if(sum1<sum2) return -1;
        return 0;
    }
};