class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        set<int> st;
        int c=0;
        for(auto it : mp){
            int freq = it.second;
            while(st.find(freq)!=st.end() && freq>0){
                freq--;
                c++;
            }
            st.insert(freq);
        }
        return c;
    }
};