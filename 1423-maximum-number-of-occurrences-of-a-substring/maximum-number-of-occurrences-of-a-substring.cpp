class Solution {
public:
    int maxFreq(string v, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int>m;

        unordered_map<char,int>ma;

        int n = v.size();
        for(int i = 0;i<n;i++){
            ma[v[i]]++;
            if(i>=minSize){
                ma[v[i-minSize]]--;
                if(ma[v[i-minSize]] == 0){
                    ma.erase(v[i-minSize]);
                }
            }

            if(i>=minSize-1 && ma.size() <= maxLetters){
                string temp = v.substr(i-minSize+1,minSize);
                m[temp]++;
            }
        }

        int ans = 0;
        for(auto i:m){
            ans = max(ans,i.second);
        }

        return ans;

    }
};