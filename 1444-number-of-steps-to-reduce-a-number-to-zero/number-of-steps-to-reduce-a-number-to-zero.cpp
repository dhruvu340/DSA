class Solution {
public:

    int solve(int n){
        if(n==1||n==0){
            return 1;
        }


        if(n&1){
            return 1+solve(n-1);
        }else{
            return 1+solve(n/2);
        }
    }
    int numberOfSteps(int num) {
        if(num==0)return 0;
        return  solve(num);
    }
};