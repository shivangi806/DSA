class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int c=1;
        if(n==1) return c ;
        int ans = INT_MIN ;
        for(int i=0;i<n-1;i++){
            if((s[i+1]-'a')-( s[i]-'a')==1){
              c++;
            }
            else{
                c=1;
            }
            ans = max( ans , c) ; 
        }
        return ans;
    }
};