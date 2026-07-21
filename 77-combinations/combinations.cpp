class Solution {
public:
    vector<vector<int>>ans;
    void solve(int n,int k,vector<int>&temp,vector<bool>&vis){
        if(k<=0){
            ans.push_back(temp);
            return;
        }

        for(int i=1;i<=n;i++){
            if(!vis[i] &&  (temp.empty()||temp.back()<i)){
                vis[i]=true;
                temp.push_back(i);
                solve(n,k-1,temp,vis);
                vis[i]=false;
                temp.pop_back();
            }
        }


    }
    vector<vector<int>> combine(int n, int k) {
        vector<bool>vis(n+1,false);
        vector<int>temp;
        solve(n,k,temp,vis);
        return ans;
    }
};