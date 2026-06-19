class NumArray {
public:
    vector<long long>prefix;
    NumArray(vector<int>& nums) {
        prefix = vector<long long>(nums.size());
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] += prefix[i-1]*1LL + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left <= 0) return prefix[right];
        return prefix[right] - prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */