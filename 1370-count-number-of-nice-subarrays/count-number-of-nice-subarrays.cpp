class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int>m;
        m[0] = 1;
        int ct = 0 ;
        int ans = 0;
        for(auto i:nums){
            ct += (i&1);
            int toCheck = ct - k ;
            if(m.find(toCheck)!=m.end()){
                ans += m[toCheck];
            }
            m[ct]++;
        }


        return ans;
    }
};