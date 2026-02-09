class Solution {
public:
    int search(vector<int>& a, int target) {
        int n=a.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(a[mid]==target)return mid;
            else if(a[mid]<=a[r]){
                if(a[mid]<target&&a[r]>=target)l=mid+1;
                else r=mid-1;
            }else{
                if(a[mid]>target&&target>=a[l])r=mid-1;
                else l=mid+1;
            }
        }

        return -1;
    }
};