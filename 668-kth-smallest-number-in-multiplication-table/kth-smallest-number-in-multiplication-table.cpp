class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=1;
        int r=m*n;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int ct=0;
            for(int i=1;i<=m;i++){
                ct+=min(mid/i,n);
            }
            if(ct>=k){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }

        }
        return ans;
    }
};