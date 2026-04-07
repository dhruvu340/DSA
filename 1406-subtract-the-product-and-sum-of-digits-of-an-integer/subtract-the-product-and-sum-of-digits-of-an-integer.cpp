class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        int p=1, sum=0;
        while(n!=0){
            int d = n%10;
            p=p*1LL*d;
            sum=sum*1LL+d;
            n/=10;
        }
        return p-sum;
    }
};