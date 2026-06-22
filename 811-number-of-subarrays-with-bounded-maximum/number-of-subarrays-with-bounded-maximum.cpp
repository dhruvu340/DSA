class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int n = nums.size();
        
        int ct = 0;
        long long lessThanleft = 0;
        long long greaterThanRight = 0;
        set<pair<int,int>>s;
        for(int l = 0 , r= 0 ;r<nums.size();r++){
            s.insert({nums[r],r});
            while(l<=r && s.size() != 0 && s.rbegin()->first > right){
                greaterThanRight+=1LL*n-r;
                s.erase({nums[l],l});
                l++;
            }
        }
        s = set<pair<int,int>>();
        for(int l = 0 , r= 0 ;r<nums.size();r++){
            s.insert({nums[r],r});
            while(l<=r && s.size() != 0 && s.rbegin()->first >= left){
                lessThanleft+=1LL*n-r;
                s.erase({nums[l],l});
                l++;
            }
        }


        return lessThanleft - greaterThanRight;
    }
};