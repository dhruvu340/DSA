class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n =nums.size();
        int ans=0;
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                v[i] = 1;
            }
        }
        for(int i=1;i<n;i++){v[i]+=v[i-1];}


        for(int i = 0;i<n;i++){ 
            for(int j = i;j<n;j++){
                int freq = v[j] - ((i-1>=0)?v[i-1]:0);
                if(freq > (j-i+1)/2){
                    ans++;
                }
            }
        }

        return ans;
    }
};