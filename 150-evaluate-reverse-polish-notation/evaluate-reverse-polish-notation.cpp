class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto i:tokens){
            if(i=="+"||i=="-"||i=="/"||i=="*"){
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();

                if(i=="+"){
                    s.push(first+second);
                }else if(i=="-"){
                    s.push(second-first);
                } else if(i=="*"){
                    s.push(second*first);
                }else {
                     s.push(second/first);
                }

                
            }else{
                s.push(stoi(i));
            }
        }


        return s.top();
    }
};