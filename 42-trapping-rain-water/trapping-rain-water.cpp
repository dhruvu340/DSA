class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxl=0;
        int maxr=0;
        while(l<=r){
            if(height[l]<=height[r]){if(height[l]>=maxl){
                maxl=(height[l]);
            }else{
                ans+=maxl-height[l];
            }l++;}else{
                if(height[r]>=maxr){
                    maxr=height[r];
                }else{
                    ans+=maxr-height[r];
                }
                r--;
            }
        }
        return ans;
    }
};