class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        map<char ,unordered_set<string>> m;
        for(auto it : ideas){
            m[it[0]].insert(it.substr(1));
        }
        
        long long ans =0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                unordered_set<string> temp1 , temp2;
                temp1 = m[i+'a'];
                temp2 = m[j+'a'];
                long long rem =0;
                for(auto x : temp1){
                 if(temp2.find(x)!=temp2.end()){
                     rem++;
                 }    
                }
                ans+= (temp1.size()-rem)*(temp2.size()-rem)*2 ;
                
            }
        }
        return ans;
    }
};