class Solution {
public:
    bool search(vector<int>& a, int target) {
        int l=0;
        int r=a.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(a[mid]==target)return true;
             if(a[mid]==a[l]&&a[mid]==a[r]){
                r--;
                l++;

            }else if(a[l]<=a[mid]){
                if(a[l]<=target&&target<a[mid])r=mid-1;
                else l=mid+1;
            }else{
                if(a[r]>=target&&target>a[mid])l=mid+1;
                else r=mid-1;
            }

        }
        return false;
    }
};