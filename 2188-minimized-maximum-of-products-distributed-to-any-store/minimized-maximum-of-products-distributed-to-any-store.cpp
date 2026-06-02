class Solution {
public:
    int minimizedMaximum(int n, vector<int>& v) {
        int  l =1;
        int r = *max_element(v.begin(),v.end());
        int ans = 0;
        auto checker = [&](int mid)->bool{
            int ct = 0;
            for(auto i:v){
                ct += ceil((long double)i/mid);
            }
            cout<<ct<<endl;
            return ct <= n;
        };
        while(l<=r){
            int mid = l + ( r - l )/2;
            if(checker(mid)){
                ans = mid;
                r=mid-1;

            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};