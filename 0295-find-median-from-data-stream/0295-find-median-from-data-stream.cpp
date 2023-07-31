class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(left.size()>0 && left.top()<num){
            right.push(num);
        }
        else{
            left.push(num);
        }
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
        else if(left.size()+1<right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        int n = left.size();
        int m = right.size();
        if(n==m){
            int s1 = left.top()+right.top();
            return s1/2.0;
        }
        if(n>m) return left.top();
        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */