class Solution {
public:
    int hammingWeight(int n) {
        int ct;
        while(n>0){
            ct++;
            n=n&(n-1);

        }

        return ct;
    }
};