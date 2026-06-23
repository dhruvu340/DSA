class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int n =v.size();
        int ans = INT_MAX;
        int sum  = 0;
        int toFind = accumulate(v.begin(),v.end(),0) - x;
        for(int l = 0, r = 0 ;r<n;r++){
            sum += v[r];
            while(l<=r&&sum>toFind){
                sum-=v[l];
                l++;
            }
            if(sum == toFind){
                ans = min(ans,n - (r-l+1));
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};