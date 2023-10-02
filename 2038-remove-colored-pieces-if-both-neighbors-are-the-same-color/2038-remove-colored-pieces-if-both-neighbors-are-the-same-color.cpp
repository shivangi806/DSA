class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.size();
        int ca=0,cb=0;
        for(int i=0;i<n-2;i++){
           if(s[i]=='A' && s[i+1]=='A' && s[i+2]=='A'){
               ca++;
           }
            if(s[i]=='B' && s[i+1]=='B' && s[i+2]=='B'){
               cb++;
           }
        }
        if(ca>cb) return 1;
        return 0;
    }
};