class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int n = v.size();
        int sumtofind = accumulate(v.begin(),v.end(),0) - x;
        int l = 0;
        int ans = INT_MAX;
        int sum = 0;
        int i;
        for( i=0;i<n;i++){
            sum += v[i];
            while(l<=i&&sum>sumtofind){
                
                sum-=v[l];
                l++;
            }
            if(sum==sumtofind){
            ans = min(ans,n-(i-l+1));
        }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};