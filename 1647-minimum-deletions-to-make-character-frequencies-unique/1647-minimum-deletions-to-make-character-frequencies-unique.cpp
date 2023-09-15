class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<int> v;
        for(auto it : mp){
            v.push_back(it.second);
            // cout<<it.second<<endl;;
        }
        set<int> st;
        int c=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            while(st.find(v[i])!=st.end() && v[i]>0){
                v[i]--;
                c++;
            }
            st.insert(v[i]);
        }
        return c;
    }
};