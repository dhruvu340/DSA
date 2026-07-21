class Solution {
public:
    vector<vector<int>>ans;
    void solve(int n,int k,vector<int>&temp,int c){
        
        if(k<=0){
            ans.push_back(temp);
            return;
        }

        if(c > n)return ;

        temp.push_back(c);
        solve(n,k-1,temp,c+1);

        temp.pop_back();
        solve(n,k,temp,c+1);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>temp;
        solve(n,k,temp,1);
        return ans;
    }
};