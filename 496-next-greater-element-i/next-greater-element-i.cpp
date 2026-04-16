class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>m;
        stack<int>s;
        for(int j=nums2.size()-1;j>=0;j--){
            while(!s.empty()&&s.top()<=nums2[j]){
                s.pop();
            }

            int ans = s.empty() ? -1 : s.top();
            s.push(nums2[j]);
            m[nums2[j]] = ans; 
        }


        for(auto i:nums1){
            ans.push_back(m[i]);
        }

        return ans;
    }
};