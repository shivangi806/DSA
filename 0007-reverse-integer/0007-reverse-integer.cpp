
class Solution {
public:
    #define ll long long
    int reverse(int x) {
        int sg=1;
        if(x<0) sg=-1;
        long long ans=0;
        x = abs(x);
        while(x>0){
            int dg = x%10;
            ans = ans*10 + dg;
            if(ans>=INT_MAX-1) return 0;
            x=x/10;
        }
        return sg*ans;
    }
};