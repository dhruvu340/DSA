class Solution {
public:
    vector<int>ans;
    bool iscycle(vector<vector<int>>&g,int node,vector<bool>&vis,vector<bool>&pathvis){
        vis[node]=true;
        pathvis[node]=true;
        for(auto i:g[node]){
            if(!vis[i]){
                if(iscycle(g,i,vis,pathvis)){
                    return true;
                }
            }
            else if(pathvis[i]){
                return true;
            }
        }

        pathvis[node]=false;
        ans.push_back(node);
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
         
        vector<bool>vis(g.size(),false);
        vector<bool>pathvis(g.size(),false);
        

        for(int i=0;i<g.size();i++){
           if(!vis[i]){
             iscycle(g,i,vis,pathvis);
           }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};