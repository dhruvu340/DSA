class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>m;
        for(auto i:text){
            if(i == 'b' ||i=='a'||i=='l'||i=='o'||i=='n'){
                m[i]++;
            }
        }

        int ans = text.size();
        for(auto i:m){
            if( i.first == 'l' ||i.first == 'o'){
                ans = min(ans , (int)i.second/2 );
            }
            else ans = min(ans,i.second);
        }

        return (m.size()!=5) ? 0 : ans;
    }
};