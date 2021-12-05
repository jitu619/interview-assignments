class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!st1.empty()){
            st.push(st1.top());
            st1.pop();
        }
    }
    
    int pop() {
        int top=st.top();
        st.pop();
        return top;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.size()==0?true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
