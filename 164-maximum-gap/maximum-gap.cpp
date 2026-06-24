class Solution {
public:
    int maximumGap(vector<int>& v) {
    // bucket sort 
    int n = v.size();
    if(n==1)return 0;
    int mini = *min_element(v.begin(),v.end());
    int maxi = *max_element(v.begin(),v.end());
    double bucket = (maxi - mini)*1.0/(n-1);
    if(maxi==mini)return 0;
    if(bucket < 1)bucket = 1.0;
    vector<int>vmax(n,INT_MIN),vmin(n,INT_MAX);
    if(bucket == 0)bucket = 1;
    for(int i = 0 ; i < n ; i++ ){
        int pos =  (v[i] - mini)/bucket;
        vmax[pos] = max(vmax[pos],v[i]);
        vmin[pos] = min(vmin[pos],v[i]);
    }
    int  i=0;
    int j =1;
    int ans = 0;
    while(j<n){
        if(vmin[j] == INT_MAX)j++;
        else if(vmax[i] == INT_MIN)i++;
        else{
            ans = max(ans, vmin[j] - vmax[i]);
            i++;
            j++;
        }
    }

    return ans;
    }
};