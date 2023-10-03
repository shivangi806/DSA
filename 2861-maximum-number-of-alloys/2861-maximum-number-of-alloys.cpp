class Solution {
public:
    
    #define ll long long
    bool valid(int qty ,int budget, vector<vector<int>>& mat, vector<int>& stock, vector<int>& cost,int n){
        
        ll mini = INT_MAX;
        for(int i=0;i<mat.size();i++){
            ll sum=0;
            for(int j=0;j<mat[0].size();j++){
                // considering ith machine
                ll temp = 1LL*qty*mat[i][j];
                if(temp<stock[j]){
                    continue;
                }
                else{
                    ll rem = (temp-stock[j])*cost[j];
                    sum+=rem;
                }
            }
            mini = min(mini , sum);
        }
        if(mini<=budget) return 1;
        return 0;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& mat, vector<int>& stock, vector<int>& cost) {
        
        
        int l=0 , h = 1e9;
        int ans=-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(valid(mid , budget ,mat , stock , cost,n)){
                ans = mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};