#define ll long long 
class Solution {
public:
    
    ll solve(ll i){
        if(i==1) return  0;
        if(i%2==0) return 1 + solve(i/2) ;
        return 1 + min(solve(i-1) , solve(i+1));
    }
    int integerReplacement(int n) {
        return solve(n);
    }
};