
// 2147483647  = 2^31-1
class Solution {
public:
    #define ll long long
    int reverse(int x) {
        ll ans =0;
        while(x){
            int digit = x%10;
            x=x/10;
            ans = ans*10 + digit;
            if(ans>INT_MAX || ans<INT_MIN){
                return 0;
            }
        }
        return ans;
    }
};