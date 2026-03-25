class MinStack {
public:
    stack<long long>s;
    long long int minval;
    MinStack() {
        
    }
    
    void push(int val) {
       if(s.empty()){
        minval=val;
        s.push(val);
       }else{
        if(val>=minval){
            s.push(val);
        }else{
           
            s.push(2LL*val-minval);
             minval=val;
        }

        
       }
    }
    
    void pop() {
        if(s.empty())return ;
        long long x=s.top();
        s.pop();
        if(x<minval){
            minval=2LL*minval-x;

        }
    }
    
    int top() {
        if(s.empty())return -1;
        if(s.top()<minval)return minval;
        else return s.top();
        
    }
    
    int getMin() {
       
        return minval;
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