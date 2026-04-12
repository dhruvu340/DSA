class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1;
        int r = *max_element(begin(bloomDay),end(bloomDay));
        int ans = -1;
        auto checker=[&](int mid)->bool{
            int ct=0;
            int b=0;
            for(auto i:bloomDay){
                if(i<=mid){
                    ct++;
                    if(ct==k){
                        b++;
                        ct=0;
                    }
                }else{
                    ct=0;
                }
            }
            return b>=m;

        };
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checker(mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};