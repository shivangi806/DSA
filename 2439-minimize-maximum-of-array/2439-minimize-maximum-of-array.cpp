class Solution {
public:
    #define ll long long
    bool valid(ll target , vector<int>&nums){
        ll n = nums.size();
        vector<ll> arr(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(arr[i]>target) return false ;
            arr[i+1] -= (target-arr[i]);
        }
        if(arr[n-1]>target) return false;
        return true ;
    }
    int minimizeArrayValue(vector<int>& nums){
       ll n =  nums.size();
       ll l = 0 ;
       ll h=1e9;
       while(l<h){
           ll mid = (l+h) >> 1 ;
           if(valid(mid , nums)){
               h=mid;
           }
           else l=mid+1;
       }
       return l ;
    }
};