class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m= needle.size();
        // n bada and m chota hoga tb hi possible hoga
        if(n<m) return -1;
        if(n==m && haystack==needle) return 0;
        for(int i=0;i<n;i++){
             int f=1;
            for(int j=0;j<m;j++){
                if(needle[j]!=haystack[j+i]){
                    f=0;
                    break;
                }
            }
            if(f==1){
                return i;
            }
        }
        return -1;
    }
};