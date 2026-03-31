class Solution {
public:
    stack<int>s;
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
        s.push(node);
        return false;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>>g(numCourses);
        vector<bool>vis(numCourses,false);
        vector<bool>pathvis(numCourses,false);
        for(auto i:prerequisites){
            g[i[1]].push_back(i[0]);
        }

        for(int i=0;i<numCourses;i++){
           if(!vis[i]){
             if(iscycle(g,i,vis,pathvis)){
                return {};
            }
           }
        }
        vector<int>ans;

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;


    }
};