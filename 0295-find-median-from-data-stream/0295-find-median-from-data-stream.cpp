class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> qp;
    priority_queue<int> pq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.size()==0 && qp.size()==0) pq.push(num);
        else{
            if(num>pq.top()) qp.push(num);
            else pq.push(num);
        }
        if(pq.size()>qp.size()+1){
            int x=pq.top();
            pq.pop();
            qp.push(x);
        }
        else if(qp.size()>pq.size()+1){
            int x=qp.top();
            qp.pop();
            pq.push(x);
        }
    }
    
    double findMedian() {
        if(pq.size()>qp.size()) return (double)pq.top();
        else if(qp.size()>pq.size()) return (double)qp.top();
        else{
            double x=qp.top();
            double y=pq.top();
            return (x+y)/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */