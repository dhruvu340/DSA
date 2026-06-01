class Solution {
public:
    int solve(vector<int>&nums,int k){
        int l = 0;
        map<int,int>m;
        
        int ans = 0 ;
        for(int r=0;r<nums.size();r++){
            m[nums[r]]++;
           
            while(m.size()>k){
                
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    m.erase(nums[l]);
                }
                l++;
            }
            ans+=r-l+1;
            
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans  = solve(nums,k) - solve(nums,k-1);
        return ans;
    }
};