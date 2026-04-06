class Solution {
public:
    bool judgeCircle(string moves) {
        
        int l=0,r=0,d=0,u=0;

        for(auto i:moves){
            if(i=='U'){
                u++;
            }
            else if(i=='D'){
                d++;
            }else if(i=='R'){
               r++;
            }else if(i=='L'){
                l++;
            }
        }


        return r==l && d==u;
    }
};