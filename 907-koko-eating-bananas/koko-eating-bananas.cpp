class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans=r;

        auto solve = [&](int mid)->bool{
            long long h_new=0;
            for(auto i:piles){
                h_new+=ceil((long double)i/mid);
            }

            return h_new<=h;
        };
        while(l<=r){
            int mid = l + (r-l)/2;
            if(solve(mid)){
                ans=min(ans,mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};