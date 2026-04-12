class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int l = 0;
        int r = *max_element(price.begin(),price.end());
        int ans=-1;
        auto checker = [&](int minDifference)->bool{
            int el=price[0];
            int ct=1;
            for(int i=1;i<price.size();i++) {
                if(abs(price[i]-el)>=minDifference){
                    ct++;
                    el=price[i];
                }
                if(ct>=k)return true;
            }
            return false;
        };
        while(l<=r){
            int mid = l + (r-l)/2;
            if(checker(mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};