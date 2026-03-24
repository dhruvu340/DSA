class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int i=0;
        int r=n-1;
        int maxl=0;
        int maxr=0;
        while(i<=r){
            if(height[i]<=height[r]){
                if(maxl<height[i]){
                    maxl=height[i];
                }else{
                    if(maxl-height[i]>0){
                        ans+=maxl-height[i];
                    }
                }
                i++;
            }else{
                if(maxr<height[r]){
                    maxr=height[r];
                }else{
                    if(maxr-height[r]>0){
                        ans+=  maxr-height[r];
                    }
                }
                r--;

            }
        }
        return ans;
    }
};