class MinStack {
    stack<int> valueStack;
    stack<int> minValueStack;
public:
    MinStack() {}
    
    void push(int val) {
        valueStack.push(val);
        if (!minValueStack.empty()) {
            val = min(val, minValueStack.top());
        }
        minValueStack.push(val);
    }
    
    void pop() {
        valueStack.pop();
        minValueStack.pop();
    }
    
    int top() {
        return valueStack.top();
    }
    
    int getMin() {
        return minValueStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */