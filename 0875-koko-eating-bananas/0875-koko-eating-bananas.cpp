
class Solution {
public:
    
    #define ll long long
    int minEatingSpeed(vector<int>& piles, int h) {
        // k varies from smallest pile value till largest pile value
        sort(piles.begin(),piles.end());
        ll n = piles.size();
        ll start = 1;
        ll end = piles[n-1];
        while(start<=end){
            ll mid = start + (end-start)/2;
            ll hr = 0;
            for(int i=0;i<n;i++){
                ll temp = piles[i];
                if(temp%mid==0) hr+=temp/mid;
                else hr+=(temp/mid + 1);
            }
            if(hr>h) start = mid+1;
            else  end=mid-1;
        }
        return start ;
    }
};