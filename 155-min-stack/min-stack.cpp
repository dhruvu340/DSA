class MinStack {
public:
    stack<long long>s;
    long long mini;
    MinStack() {
        s= stack<long long>();
        mini=INT_MAX;
    }
    
    void push(int val) {

        if(s.empty()){
            mini=val;
            s.push(val);
        }
        else{
            if(val>=mini){
                s.push(val);
            }else{
                s.push(((long long)2*1LL*val-mini));
                mini=val;
            }
        }
    }
    
    void pop() {
        if(s.empty())return ;
        if(s.top()<mini){   
            mini=((long long)2*mini-s.top());
        }
        s.pop();
    }
    
    int top() {
    
        return (s.top() < mini) ? mini : s.top();
    }
    
    int getMin() {
       
        return mini;
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