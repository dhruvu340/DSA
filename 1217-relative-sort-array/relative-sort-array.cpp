class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxel = *max_element(arr1.begin(),arr1.end());
        vector<int>count(maxel+1);
        vector<int>ans;
        for(auto i:arr1)count[i]++;
        for(auto i:arr2){
            while(count[i]>0){
                ans.push_back(i);
                count[i]--;
            }
        }
        for(int i=0;i<=maxel;i++){
            while(count[i]>0){
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }
};