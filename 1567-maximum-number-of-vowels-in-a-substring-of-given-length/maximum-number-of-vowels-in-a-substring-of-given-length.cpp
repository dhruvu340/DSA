class Solution {
public:
    int maxVowels(string v, int k) {
        int ct = 0;
        int ans =0;
        for(int i=0;i<v.size();i++){
            if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u' ){
                ct++;
            }
            if(i>=k){
                ct -= (v[i-k] == 'a' || v[i-k] == 'e' || v[i-k] == 'i' || v[i-k] == 'o' || v[i-k] == 'u' );
            }
            if(i>=k-1){
                ans=max(ans,ct);
            }
        }
        return ans;
    }
};