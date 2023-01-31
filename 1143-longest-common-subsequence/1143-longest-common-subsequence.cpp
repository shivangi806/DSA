class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        int t[n+1][m+1];
        // initialisation for top down
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        // choice diagram in matrix format
        // text1 -- in top to bootom
        // text2 -- in left to right
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                // if matching
                if(text1[i-1]==text2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                // if not matching
                else{
                   // we have two choices
                    t[i][j] = max(t[i-1][j]  , t[i][j-1]);
                }
            }
        }
        return t[n][m] ;
    }
};