class Solution {
public:
    string reverseByType(string s) {
        stack<int> s1;
        stack<int> s2;
        for(auto i:s){
            if(i<=122&&i>=97){
                s1.push(i);
            }else{
                s2.push(i);
            }
        }
        string ans="";
        for(auto i:s){
            if(i<=122&&i>=97){
                ans+=s1.top();
                s1.pop();
            }else{
                ans+=s2.top();
                s2.pop();
            }
        }


        return ans;
    }
};