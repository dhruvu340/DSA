class MinStack {
public:
    stack<int>s;
    stack<int>minstack;
    MinStack() {
        s= stack<int>();
        minstack=stack<int>();
    }
    
    void push(int val) {
        if(minstack.empty()||minstack.top()>=val){
            minstack.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(s.empty())return ;
        if(s.top()==minstack.top()){
           
            minstack.pop();
        }
        s.pop();
    }
    
    int top() {
    
        return s.top();
    }
    
    int getMin() {
       
        return minstack.top();
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