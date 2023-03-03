class Solution {
public:
    int strStr(string haystack, string needle) {
        // next method
        // by first finding the first character of needle in haystack and then check the substring is equal or not if not then move forward to chcek another i position in haystack where we found the first character of the needle
        
        int n= haystack.size();
        int m = needle.size();
        int ans =-1;
        int i=0;
        while(i<n){
            // find first character of needle in haystack
            auto itr = find(haystack.begin()+i,haystack.end(),needle[0]);
            // now substring check karenge
            int pos = itr-haystack.begin();
            string str = haystack.substr(pos , m);
            if(str==needle) {
                ans = pos;
                break;
            }else{
                i++;
            }
        }
        return ans;
    }
};