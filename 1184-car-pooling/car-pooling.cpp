class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(1002,0);
        for(auto i:trips){
            diff[i[1]] += i[0];
            diff[i[2]] -= i[0];
        }

        for(int i=1;i<1002;i++)diff[i] += diff[i-1];

        bool ans = true;
        for(auto i:diff){
            if(i>capacity){
                ans=false;
                break;
            }
        }


        return ans;
    }
};