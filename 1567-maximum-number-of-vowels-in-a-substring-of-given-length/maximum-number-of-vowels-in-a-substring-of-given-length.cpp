class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string v, int k) {
        int ct = 0;
        int ans = 0;
        int l = 0;

        for(int r = 0;r<v.size();r++){
            if(isVowel(v[r])){
                ct++;
                cout<<ct<<endl;
            }


            if(r>=k){
               if(isVowel(v[l])){ ct--;}
                l++;
                
            }
            

            if(r>=k-1){ans = max(ans,ct); cout<<"ans ->" <<ans<<endl;}
        }


        return ans;
    }
};