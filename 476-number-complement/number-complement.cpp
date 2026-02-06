class Solution {
public:
    int findComplement(int num) {
        int sig=31-__builtin_clz(num);
        for(int i=0;i<=sig;i++){
            int mask=1LL<<i;
            if(num&mask){
                num^=mask;
            }else{
                num|=mask;
            }
        }
        return num;
    }
};