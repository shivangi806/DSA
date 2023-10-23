class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1){
            if(n%4!=0) return 0;
            n=n/4;
        }
        if(n==1) return 1;
        return 0;
    }
};