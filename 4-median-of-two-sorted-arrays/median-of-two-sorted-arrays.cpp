class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m)return findMedianSortedArrays(nums2,nums1);
        int l = 0;
        int r = n;

        while(l<=r){
            int mid = l + (r-l)/2;
            int rest = (m+n+1)/2-mid;
            int x1 = (mid==0)?INT_MIN:nums1[mid-1];
            int x2=(rest==0)?INT_MIN:nums2[rest-1];
            int x3=(mid==n)?INT_MAX:nums1[mid];
            int x4=(rest==m)?INT_MAX:nums2[rest];

            if(x1<=x4&&x2<=x3){
                if((m+n)%2==0){
                    return (max(x1,x2)+min(x3,x4))/2.0;
                }else{
                    return max(x1,x2);
                }
            }

            if(x1>x4){
                r=mid-1;
            }else if(x2>x3){
                l=mid+1;
            }
        }

        return -1;
    }
};