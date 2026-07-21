class Solution {
public:

    int solve(int currNo,int n,vector<bool>&vis){
        if(currNo==n)return 1;
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(vis[i]!=true&&(i%(currNo+1)==0||(currNo+1)%i==0)){
                vis[i]=true;
                ans+=solve(currNo+1,n,vis);
                vis[i]=false;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<bool>vis(n+1,false);
        

        return solve(0,n,vis);
    }
};