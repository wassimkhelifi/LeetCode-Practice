class MyQueue {
    stack<int> inStack;
    stack<int> outStack;
public:
    MyQueue() {}
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if (outStack.empty()) fillOutStack();
        int result = outStack.top();
        outStack.pop();
        return result;
    }
    
    int peek() {
        if (outStack.empty()) fillOutStack();
        return outStack.top();
    }
    
    bool empty() {
        return outStack.empty() && inStack.empty();
    }
    
    void fillOutStack() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
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