class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int k=j+1;
                int z=n-1;
                while(k<z){
                    long long sum = 1LL*nums[i] + nums[j] + nums[k] + nums[z];
                    if(sum<target){
                        k++;
                    }else if(sum>target){
                        z--;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[z]});
                        k++;
                        z--;
                        while(k<z&&nums[k]==nums[k-1]){k++;}
                        while(k<z&&nums[z]==nums[z+1]){z--;}
                    }
                }
            }
        }


        
        return ans;
    }
};