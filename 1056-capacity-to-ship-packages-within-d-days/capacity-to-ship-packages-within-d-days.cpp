class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*min_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        auto predicate = [&](int x)->bool{
            int ct = x ;
            int k=days;
            for(auto i:weights){
                if(i<=ct){
                    ct-=i;
                }else{
                    k--;
                    if(k==0)return false;
                    ct=x;
                    ct-=i;
                    if(ct<0)return false;
                }
            }

            return true;
            
        };
        int ans=INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(predicate(mid)){
                ans=min(ans,mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};