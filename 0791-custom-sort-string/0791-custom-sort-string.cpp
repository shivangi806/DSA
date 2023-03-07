class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        int m = s.size();
        map<char,int> mp;
        string ans ;
        for(int i=0;i<m;i++) mp[s[i]]++;
        for(int i=0;i<n;i++){
            char x = order[i];
            if(mp.find(x)!=mp.end()){
                auto ele = mp.find(x);
                int c= ele->second;
                for(int i=0;i<c;i++){
                    ans.push_back(x);
                }
                mp.erase(x);
            }
        }
        for(auto it : mp){
            char ele = it.first;
            int c = it.second;
            for(int i=0;i<c;i++){
              ans.push_back(ele);
            }
        }
        return ans ;
        
    }
};