class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int,int>>q;
        q.push({x,0});
        int leftLimit = 1;
        int rightLimit = 1e4;
        vector<bool>vis(rightLimit+1,false);
        vis[x] = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int front = q.front().first;
                int op = q.front().second;
                q.pop();
                if(front == y)return op;

                if(front+1<=rightLimit && vis[front + 1]==false){
                    vis[front+1]=true;
                    q.push({front+1,op+1});
                }
                if(front-1>=1 && vis[front - 1 ]==false){
                    vis[front-1]=true;
                    q.push({front-1,op+1});
                }
                if(front%5==0 && vis[front/5]==false){
                    vis[front/5]=true;
                    q.push({front/5,op+1});
                }
                if(front%11==0  && vis[front/11]==false){
                    vis[front/11]=true;
                    q.push({front/11,op+1});
                }
            }
        }
        return -1;
    }
};