class Solution {
public:
    bool isValid(string st) {
        stack<int>s;
        for(auto i:st){
            
            if(i=='('){
                s.push(i);
            }else if(i==')'){
                if(s.empty())return false;
                if(s.top()=='('){
                    s.pop();
                }else{
                    return false;
                }
            }else if(i=='{'){
                s.push(i);
            }else if(i=='}'){
                  if(s.empty())return false;
                 if(s.top()=='{'){
                    s.pop();
                }else{
                    return false;
                }
            }else if(i=='['){
                s.push(i);
            }else if(i==']'){
                  if(s.empty())return false;
                if(s.top()=='['){
                    s.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }

        return true && s.empty();
    }
};