class MinStack {
    vector<int> numbers;
    int min = INT_MAX;
public:
    MinStack() {}
    
    void push(int val) {
        numbers.push_back(val);
        if (val < min) {
            min = val;
        }
    }
    
    void pop() {
        numbers.pop_back();
        update();
    }
    
    int top() {
        return numbers.back();
    }
    
    int getMin() {
        return min;
    }
    
    void update() {
        min = INT_MAX;
        for (auto& number : numbers) {
            if (number < min) {
                min = number;
            }
        }
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