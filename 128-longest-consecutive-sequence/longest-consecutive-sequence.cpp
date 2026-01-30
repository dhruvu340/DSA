class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int ans=1;
        unordered_set<int>s;
        for(auto i:nums)s.insert(i);
        for(auto i:s){
            if(s.find(i-1)==s.end()){
                int ct=1;
                int st=i+1;
                while(s.find(st)!=s.end()){
                    ct++;
                    st=st+1;
                }
                ans=max(ans,ct);
            }
        }


        return ans;
    }
};