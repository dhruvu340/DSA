class Solution {
public:

    
    const long long MOD=1e9+7;
    long long binaryexpoIterative(long long base,long long n){
    long long res = 1;

    base = base % MOD;

    while(n>0){
        if(n&1){
            res = (res*base)%MOD ;
        }

        base=(base*base)%MOD;

        n = n>>1;
    }

    return res;
}

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd=   n/2;

        long long optionsodd = binaryexpoIterative(4,odd);
        long long optioneven = binaryexpoIterative(5,even);

        return ((optionsodd%MOD)*1LL*(optioneven%MOD))%MOD;
    }
};