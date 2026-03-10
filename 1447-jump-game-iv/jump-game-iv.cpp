class Solution {
public:
    int minJumps(vector<int>& arr) {
        vector<int>visited(arr.size(),false);
        unordered_map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }

        queue<int>q;
        q.push(0);
        visited[0]=true;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();
                int left=curr-1;
                int right=curr+1;
                if(curr==arr.size()-1)return steps;
                if(left>=0&&!visited[left]){
                    q.push(left);
                    visited[left]=true;
                }
                if(right<arr.size()&&!visited[right]){
                    q.push(right);
                    visited[right]=true;
                }

                for(auto i:m[arr[curr]]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i]=true;
                    }
                }
                m.erase(arr[curr]);
            }
            steps++;
        }


        return -1;
    }
};