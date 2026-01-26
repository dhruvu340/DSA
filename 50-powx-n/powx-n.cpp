class Solution {
public:
    double solve(double x,long N ){
        if (N==0)return 1.0;
       
        if(N<0){
           return solve(1/x,-N);
        }
        if(N%2){
            return x * solve(x*x,N/2);
        }else{
            return solve(x*x,N/2);
        }
    }
    double myPow(double x, long long n) {
       return solve(x,(long)n);
    }
};