class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n=nums1.size();
        int m=nums2.size();
        
        long long l=-1e10;
        long long r=1e10;
        long long ans=-1;
        auto checker=[&](long long x)->bool{
            long long ct=0;
            for(int i=0;i<n;i++){
                if(nums1[i]>0){int l=0;
                int r=m-1;
                int mi=-1;
                while(l<=r){
                    int mid = l+(r-l)/2;
                    long long p=nums1[i]*1LL*nums2[mid];
                    if(p<=x){
                        mi=mid;
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }ct+=(mi+1);
                }else if(nums1[i]<0){

                    int l=0;
                int r=m-1;
                int mi=m;
                while(l<=r){
                    int mid = l+(r-l)/2;
                    long long p=nums1[i]*1LL*nums2[mid];
                    if(p<=x){
                        mi=mid;
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                }

                ct+=(m-mi);

                }else{
                    if(x>=0)ct+=m;
                }
            }
            return ct>=k;
        };
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(checker(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;

    }
};