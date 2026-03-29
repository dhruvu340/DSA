class Solution {
public:

    bool bfs(vector<vector<int>>& graph,int node , vector<int>&color,int curr){
        queue<int>q;
        q.push(node);
        color[node]=curr;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int currentNode = q.front();
                int currentColor=color[currentNode];
                q.pop();
                for(auto i:graph[currentNode]){
                    if(color[i]==-1){
                        if(currentColor==0){
                            color[i]=1;
                        }else{
                            color[i]=0;
                        }

                        q.push(i);
                    }else if(color[i]==currentColor){
                        return false;
                    }
                }
            }
        }


        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!bfs(graph,i,color,0)){
                    return false;
                }
            }
        }
        return true;
    }
};