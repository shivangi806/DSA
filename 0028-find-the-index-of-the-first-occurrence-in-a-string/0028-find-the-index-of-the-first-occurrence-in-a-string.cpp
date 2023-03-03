class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= haystack.size();
        int m = needle.size();
        // for finding the target string in given string and storing the first starting index of it in the element  ans
        int ans = haystack.find(needle);
        // after that checking ki vo subtring h ya ni 
        if(ans!= string :: npos) return ans;
        return -1;
    }
};