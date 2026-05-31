class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxel = *max_element(arr1.begin(), arr1.end());
        vector<int> ct(maxel + 1, 0);
        for (auto i : arr1)
            ct[i]++;
        vector<int> ans;
        for (auto i : arr2) {
            while (ct[i] > 0) {
                ans.push_back(i);
                ct[i]--;
            }
        }
        for (int i = 0; i <= maxel; i++) {
            while (ct[i] > 0) {
                ans.push_back(i);
                ct[i]--;
            }
        }
        return ans;
    }
};