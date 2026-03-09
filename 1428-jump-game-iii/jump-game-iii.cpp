class Solution {
public:
    
    bool canReach(vector<int>& arr, int start) { 
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            if(idx<0||idx>=arr.size()||arr[idx]<0)continue;
           
            if(arr[idx]==0)return true;
            int jump=arr[idx];
            arr[idx]=-1;
            q.push(idx+jump);
            q.push(idx-jump);
            
            
        }

        return false;
     }
};