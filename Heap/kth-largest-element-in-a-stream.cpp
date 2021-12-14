class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minq;
    int heapsize;
    KthLargest(int k, vector<int>& nums) { 
        for(int i:nums){
            minq.push(i);
        }
        heapsize=k;
         while(minq.size()>heapsize){
            minq.pop();
        }
        
    }
    
    int add(int val) {
        minq.push(val);
        while(minq.size()>heapsize){
            minq.pop();
        }
        return minq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
