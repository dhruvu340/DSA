class Solution {
public:
    bool detectCapitalUse(string word) {
        int ct=0;
        int flag = false;
        for(auto i:word){
            if(islower(i)){
                ct++;
            }
        }
        if(ct==word.size()){
            flag=true;
        }

        int ct1 = 0;
        for(auto i:word){
            if(isupper(i)){
                ct1++;
            }
        }
        if(ct1==word.size()){
            flag=true;
        }

        if(ct == word.size() -1 && isupper(word[0])){
            flag=true;
        }



        return flag;
        
    }
};