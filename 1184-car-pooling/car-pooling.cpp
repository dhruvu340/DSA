class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<long long>v(1001,0);
        for(auto i:trips){
            int add=i[0];
            int st=i[1];
            int end=i[2];
            v[st]+=add;
            if(end<1001){
                v[end]-=add;
            }
        }

        for(int i=1;i<1001;i++){
            v[i]+=1LL*v[i-1];
        }

        for(auto i:v){
            if(i>capacity)return false;
        }

        return true;
    }
};