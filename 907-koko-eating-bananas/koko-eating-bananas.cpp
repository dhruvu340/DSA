class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=-1;
        auto checker=[&](int mid)->bool{
            long long ct = 0;
            for(auto i:piles){
                ct+=1LL*ceil((long double)i/mid);
            } 
            return ct<=h;
        };
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checker(mid)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};