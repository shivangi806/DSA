class Solution {
public:
    
    bool valid (string &a,string &b, string &order){
        int i=0;
        while(i<a.size() && a[i]==b[i]) i++;
        if(i==a.size()) return 1;
        else if (i==b.size()) return 0;
        else return (order.find(a[i]) < order.find(b[i]));
    }
    bool isAlienSorted(vector<string>& words, string order) {
        // map<int,int> m;
        // for(int i=0;i<order.size();i++){
        //     m[order[i]-'a']=i;
        // }
        for(int i=0;i<words.size()-1;i++){
            if(!valid(words[i],words[i+1],order)) return 0;
        }
        return 1;
    }
};