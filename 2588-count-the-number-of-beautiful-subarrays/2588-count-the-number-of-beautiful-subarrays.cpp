class Solution {
public:
    #define ll long long
    long long beautifulSubarrays(vector<int>& nums) {
        ll n = nums.size();
        map<ll,ll> mp;
        ll c=0;
        ll x =0;
        mp[0]++;
        vector<ll> ps(n+1);
        ps[0]=0;
        for(int i=0;i<n;i++){
            ps[i+1]=ps[i]^nums[i];
        }
        for(int i=1;i<=n;i++){
            if(mp.find(ps[i])!=mp.end()){
                c+=mp[ps[i]];
            }
            mp[ps[i]]++;
        }
        return c;
    }
};