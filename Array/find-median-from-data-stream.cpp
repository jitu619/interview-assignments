class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh.empty()){
            maxh.push(num);
        }else if(maxh.size()>minh.size()){
            if(maxh.top()>num){
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(num);
            }else minh.push(num);
        }else{
            if(minh.top()<num){
                maxh.push(minh.top());
                minh.pop();
                minh.push(num);
            }else maxh.push(num);
        }
    }
    
    double findMedian() {
        if((maxh.size()+minh.size())%2)
            return maxh.top();
        return double(maxh.top()+minh.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
