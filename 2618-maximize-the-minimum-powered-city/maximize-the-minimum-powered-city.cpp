using ll=long long; 
class Solution {
public:
    bool checker(ll mid,vector<ll>diff,ll n,ll k ,ll r){
        ll cumm=0;
        
        for(int i=0;i<n;i++){
            cumm+=diff[i];
            if(cumm<mid){
                ll need=mid-cumm;
                if(need>k){
                    return false;
                }
                k-=need;
                
                if(i+2*r+1<n){
                    diff[i+2*r+1]-=need;
                }
                cumm+=need;
            }
        }

        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        ll n=stations.size();
        vector<ll>diff(n,0);
        for(int i=0;i<n;i++){
            diff[max(0,i-r)]+=stations[i];
            if(i+r+1<n){
                diff[i+r+1]-=stations[i];
            }
        }

        

        ll left=0;
        ll right=1e18;
        ll ans=-1;
        while(left<=right){
            ll mid=left+(right-left)/2;
            if(checker(mid,diff,n,k,r)){
                left=mid+1;
                ans=mid;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};