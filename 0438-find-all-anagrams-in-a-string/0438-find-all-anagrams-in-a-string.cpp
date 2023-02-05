class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // basically we need to find the anagrams for string p ...returning all the starting point of all
        int n1=s.size();
        int n2 =p.size();
        vector<int> res ;
        if(n1 < n2) return {};
        vector<int> freqP(26,0);
        vector<int> window(26,0);
        for(int i=0;i<n2;i++){
            freqP[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(freqP==window) res.push_back(0);
        for(int i=n2;i<n1;i++){
            window[s[i-n2]-'a']--;
            window[s[i]-'a']++;
            if(window==freqP) res.push_back(i-n2+1);
        }
        return res ;
    }
};