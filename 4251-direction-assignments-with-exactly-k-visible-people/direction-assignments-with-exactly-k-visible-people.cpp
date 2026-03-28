
class Solution {
public:
    
     int fact[100001], invfact[100001];
    const int MOD=1e9 + 7;
    int modpow(int base,int p){ int ans=1; base%=MOD;   while(p){if(p%2==1){ ans= modmul(base,ans);}  base=modmul(base,base); p/=2;}return ans;}
    int modinv(int a) { return modpow(a, MOD - 2);}
     int modmul(int a,int b){return ((a%MOD)*1LL*(b%MOD))%MOD;}
    void precompute() { fact[0] = 1;for (int i = 1; i <= 100000; i++) { fact[i] = modmul(fact[i-1], i);  } invfact[100000] = modinv(fact[100000]); for (int i = 100000-1; i >= 0; i--) {invfact[i] = modmul(invfact[i+1], i+1);}}
    int nCr(int n, int r) { if (r < 0 || r > n) return 0; return modmul(fact[n], modmul(invfact[r], invfact[n-r]));}
   

    int countVisiblePeople(int n, int pos, int k) {
        precompute();
        int ans =  modmul(2 , nCr(n-1,k)) ;

        return ans;
    }
};