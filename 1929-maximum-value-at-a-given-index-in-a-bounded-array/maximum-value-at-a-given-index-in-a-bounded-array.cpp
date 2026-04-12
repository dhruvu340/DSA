class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long l=1;
        long long r=maxSum;
        long long ans=-1;
        long long leftr=index;
        long long rightr=n-index-1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            long long leftSum=0,rightSum=0,el=mid-1;

            if(leftr<=el){
                leftSum=(el*1LL*(el+1)/2)  - ((el-leftr)*1LL*(el-leftr+1)/2);
            }else{
                leftSum=el*1LL*(el+1)/2 + (leftr-el)*1LL;
            }
            if(rightr<=el){
                rightSum=(el*1LL*(el+1)/2)  - ((el-rightr)*1LL*(el-rightr+1)/2);
            }else{
                rightSum=el*1LL*(el+1)/2 + (rightr-el)*1LL;
            }

            long long currSum=leftSum+mid+rightSum;
            if(currSum<=maxSum){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};