class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
           mp[s[i]]++;
        }
        string ans ;
        priority_queue<pair<int,char>> pq;
        for(auto it : mp){
            int fr = it.second;
            char ch = it.first;
            pq.push({fr,ch});
        }
        while(!pq.empty()){
            char ch = pq.top().second;
            int fr = pq.top().first;
            
            for(int i=0;i<fr;i++){
                ans+=ch;
            }
            pq.pop();
        }
        return ans ;
    }
};