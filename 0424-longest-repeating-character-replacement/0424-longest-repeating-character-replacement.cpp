class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int maxOcc = 0;
        int ans = 0;
        int i=0;
        int j=0;
        while(i<n){
            mp[s[i]]++;
            maxOcc = max(maxOcc , mp[s[i]]);
            int diffChar = (i-j+1) - maxOcc;
            
            if(diffChar>k){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans , i-j+1);
            i++;
        }
        return ans;
    }
};