class Solution {
public:
    #define ll long long
    int kthGrammar(int n, int k) {
        if(n==1 && k==1) return 0;
        
        ll  mid = pow(2,n-1)/2;
        if(mid>=k){
            // search in left part only;
            return kthGrammar(n-1,k);
        }
        else{
            return ! kthGrammar(n-1,k-mid);
        }
        return 0;
    }
};