class Solution {
public:
    
    int lcs(string &s, string &s2 , int n1,int n2){
        int t[n1+1][n2+1];
        for(int i=0;i<n1+1;i++){
            for(int j=0;j<n2+1;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(s[i-1]==s2[j-1]){
                   t[i][j] = 1+ t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[n1][n2] ;
    }
    bool isSubsequence(string s, string t) {
        // here if the lcs of both comes out to be the string which is smaller one then return true
        int n1 = s.size();
        int n2 = t.size();
        if(n1==0) return 1;
        if(n2==0) return 0;
        int len = min(n1,n2);
        if(lcs(s,t,n1,n2)==len) return 1;
        return 0;
    }
};