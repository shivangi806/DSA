#define ll long long 
class Solution {
public:
    map<int,int> mp ;
    ll solve(ll i){
        if(i==1) return  0;
        if(mp[i]!=0) return mp[i] ;
        if(i%2==0) return  mp[i] =  1 + solve(i/2) ;
        return mp[i] = 1 + min(solve(i-1) , solve(i+1));
    }
    int integerReplacement(int n) {
        return solve(n);
    }
};