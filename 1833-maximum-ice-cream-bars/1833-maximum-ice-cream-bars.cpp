class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n = costs.size();
        long long int sum = 0;
        int c=0;
        for(int i=0;i<n;i++){
          sum+=costs[i];
            if(sum<=coins){
               c++;
              }
        }
       if(coins > sum) return n;
       return c;
    }
};