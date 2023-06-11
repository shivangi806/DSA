class Solution {
public:
    #define ll long long
    
    ll sum(ll c , ll x){
        return c*x - (c*(c+1))/2;
    }
    ll ans = 0;
    int maxValue(int n, int index, int maxSum) {
        ll l = 1,h=maxSum;
        while(l<=h){
            ll mid = (l+h)>>1;
            
            ll lc = min((ll)(index),mid-1);
            ll rc= min((ll)(n-index-1) , mid-1);
            
            ll leftsum = sum(lc,mid);
            leftsum+=max((ll)0,(ll)(index-(mid-1)));
            
            
            ll rightsum = sum(rc,mid);
            rightsum+=max((ll)0,(ll)(n-index-1-(mid-1)));
            
            ll ttsum = leftsum+rightsum+mid;
            if(ttsum<=maxSum){
                ans = max(ans ,mid);
                l=mid+1;
            }
            else h=mid-1;
        }
        return  ans ;
    }
};