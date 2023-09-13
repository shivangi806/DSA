class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx==fx && fy==sy && t==1) return false ;
        int miniTime = max(abs(sx-fx)  , abs(sy-fy));
        if(miniTime <= t) return true;
        return false;
    }
};