class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>m;
    int maxfreq=0;
    
    FreqStack() {
       
    }
    
    void push(int val) {
        
        m[++freq[val]].push(val);
        if(freq[val]>maxfreq){
            maxfreq=freq[val];
        }
    }
    
    int pop() {
        int val= m[maxfreq].top();
         m[maxfreq].pop();
       
        if(m[freq[val]--].size()==0)maxfreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */