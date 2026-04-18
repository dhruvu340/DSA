class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        long long ans =0 ;
        int n=heights.size();
        for(int i=0;i<n;i++){
            long long maxi = heights[i];
            long long ct = heights[i];
            for(int j = i-1;j>=0;j--){
                if(heights[j]>=maxi){
                    ct+=maxi;
                }else{
                    maxi=heights[j];
                    ct+=maxi;
                }
            } 
             maxi = heights[i];
            for(int j = i+1;j<n;j++){
                if(heights[j]>=maxi){
                    ct+=maxi;
                }else{
                    maxi=heights[j];
                    ct+=maxi;
                }
            } 


            ans=max(ans,ct);
        }

        return ans;
    }
};