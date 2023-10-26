class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int c=0;
        int ans=0;
        for(int i=0;i<n;i++){
             if(s[i]=='('){
                 c++;
             }
            else if(s[i]==')'){
                c--;
            }
            ans = max(ans,c);
        }
        return ans;
    }
};