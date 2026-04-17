class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(auto i:asteroids){
            if(i>0){
                s.push(i);
            }else{
                while(!s.empty()&&s.top()>0&&s.top()<abs(i))s.pop();

                if(s.empty()||s.top()<0){
                    s.push(i);
                }else if(s.top()==abs(i)){
                    s.pop();
                }
            }
        }
        vector<int>ans;
        while(!s.empty()){ans.push_back(s.top());s.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};