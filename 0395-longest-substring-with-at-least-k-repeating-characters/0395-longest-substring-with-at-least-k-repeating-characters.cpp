class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        int breakpoint;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]<k){
                breakpoint = i ;
                break;
            }
        }
        if(breakpoint==s.size()) return s.size();
        int x = longestSubstring(s.substr(0,breakpoint),k);
        int y = longestSubstring(s.substr(breakpoint+1),k);
        return max(x,y);
    }
};