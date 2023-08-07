class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int> lp;
    priority_queue<int,vector<int>, greater<int>> rp;
    void addNum(int num) {
        if(lp.empty() || lp.top()>=num){
            lp.push(num);
        }
        else{
            rp.push(num);
        }
        
        if(lp.size()>rp.size()+1){
            rp.push(lp.top());
            lp.pop();
        }
        else if(rp.size()>lp.size()){
            lp.push(rp.top());
            rp.pop();
        }
    }
    
    double findMedian() {
        int n = lp.size()+rp.size();
        if(n%2==0){
            return double(lp.top()+rp.top())/2.0;
        }
        return lp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */