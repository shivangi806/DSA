class Solution {
public:
    
    bool alpha(char ch){
        if(ch>='a' && ch<='z') return 1;
        return 0;
    }
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(alpha(s[i])) len++;
            else{
                len = len * (s[i]-'0');
            }
        }
        string ans;
        for(int i=n-1;i>=0;i--){
            k = k % len;
            
            if(k==0 && alpha(s[i])){
                ans.push_back(s[i]);
                return ans;
            }
            
            if(alpha(s[i])){
                len--;
            }
            else{
                len = len/(s[i]-'0') ;
            }
        }
        return "";
    }
};