class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>m;
        int pairs = 0;
        long long ans = 0;
        for(int l = 0 , r = 0 ; r<n;r++){
            int initial = m[nums[r]] * ( m[nums[r]] - 1)/2;
            pairs -= initial;
            m[nums[r]]++;
            pairs += m[nums[r]] * ( m[nums[r]] - 1)/2;

            while(l<=r && pairs >= k){
                ans += 1LL*n-r;
                int initial = m[nums[l]] * ( m[nums[l]] - 1)/2;
                pairs -= initial;
                m[nums[l]]--;
                pairs += m[nums[l]] * ( m[nums[l]] - 1)/2;
                if(m[nums[l]] == 0)m.erase(nums[l]);
                l++;
            }
            
        }
        return ans;    
    }
};