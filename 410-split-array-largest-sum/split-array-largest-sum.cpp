class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        auto checker = [&](int mid){
            int ct = 0;
            int partitions=1;
            for(auto i:nums){
                if(ct+i<=mid){
                    ct+=i;
                }else{
                    partitions++;
                    ct=i;
                }
            }
            return partitions<=k;
        };
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checker(mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};