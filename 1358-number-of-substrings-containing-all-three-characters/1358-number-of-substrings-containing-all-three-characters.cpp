class Solution {
public:
    
    int atmost(string &s){
        int n = s.size();
        int i=0;
        int j=0;
        unordered_map<char,int> mp;
        int ans = 0;
        while(i<n){
            mp[s[i]]++;
            
            while(mp.size()==3){
                mp[s[j]]--;
                
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
                
                
            }
            
            ans += (i-j+1);
            i++;
        }
        
        return ans;
    }
    int numberOfSubstrings(string s) {
        long long n = s.size();
        long long totalSubarr = (n*(n+1))/2;
        long long not_abc = atmost(s);
        return totalSubarr - not_abc ;
    }
};