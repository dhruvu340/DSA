class Solution {
public:
    //0
    //01
    //0110
    //01101001
    //01101001010110

   
    int kthGrammar(int n, int k) {
       if(n==1)return 0;
       int parent = kthGrammar(n-1,(k+1)/2);
       if(k&1)return parent;
       return 1-parent;
    }
};