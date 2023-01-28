class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
       vector<vector<int>> ans;
       if(s.empty()) return ans ;
        int l = -1;
        int h = -1;
       for(int sval : s){
           if( l < 0) l = h = sval;
           else if(sval == h+1) h = sval;
           else {
               ans.push_back({l,h});
               l = h = sval  ;
           }
           
       }
        ans.push_back({l,h});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */