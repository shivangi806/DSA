class Solution {
public:
    int dis(vector<int>&p1 , vector<int>&p2){
        return abs((p1[0]-p2[0])*(p1[0]-p2[0])) + abs((p1[1]-p2[1])*(p1[1]-p2[1])) ;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> st;
        st.insert(dis(p1,p2));
        st.insert(dis(p1,p3));
        st.insert(dis(p1,p4));
        st.insert(dis(p2,p3));
        st.insert(dis(p4,p2));
        st.insert(dis(p3,p4));
        // int dis1 = abs((p1[0]-p2[0])*(p1[0]-p2[0])) + abs((p1[1]-p2[1])*(p1[1]-p2[1])) ;
        // int dis2 = abs((p1[0]-p4[0])*(p1[0]-p4[0])) + abs((p1[1]-p4[1])*(p1[1]-p4[1])) ;
        // int dis3 = abs((p1[0]-p3[0])*(p1[0]-p3[0])) + abs((p1[1]-p3[1])*(p1[1]-p3[1])) ;
        // if(dis1+dis2==dis3 || dis1+dis3==dis2 || dis2+dis3==dis1){
        //     return true;
        // }
        // return false;
        if(!st.count(0) && st.size()==2) return 1;
        return false;
    }
};