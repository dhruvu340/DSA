class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
          return findMedianSortedArrays(nums2,nums1); 
        }
        int m=nums1.size();
        int n=nums2.size();
        int l=0;
        int r=m;
        while(l<=r){
            int mid = l + ( r - l )/2;
            int rest = (m + n + 1)/2 - mid;

            int x1=(mid==0)?INT_MIN:nums1[mid-1];
            int x2 = (rest==0)?INT_MIN:nums2[rest-1];
            int r1 = (mid==m)?INT_MAX:nums1[mid];
            int r2=(rest==n)?INT_MAX:nums2[rest];

            if(x1<=r2&&x2<=r1){
                if((m+n)%2==0){
                    return (max(x1,x2)+min(r1,r2))/2.0;
                }else{
                    return max(x1,x2);
                }
            }

            if(x1>r2){
                r=mid-1;
            }else if(x2>r1){
                l=mid+1;
            }
        }

        return -1;
    }
};