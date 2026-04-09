class Solution {
public:
    string finalString(string s) {
        string ss="";

        for(auto i:s){
            if(i!='i')ss+=i;
           else{
            reverse(ss.begin(),ss.end());
           }
        }


        return ss;
      


        
    }
};