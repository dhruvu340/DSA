class Solution {
public:
    bool check(unordered_map<string,int>m,string s,int wordl){
        for(int j=0;j<s.size();j+=wordl){
            string sub = s.substr(j,wordl);
            if(m.find(sub)!=m.end()){
                if(--m[sub]==-1){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        unordered_map<string,int>m;
        int wordsi = words.size();
        int wordl = words[0].size();
        int windowSize = wordsi*wordl;
        for(auto i:words)m[i]++;
        int i = 0;
        vector<int>ans;
        while(i + windowSize <= s.size()){
            if(check(m,s.substr(i,windowSize),wordl)){
                ans.push_back(i);
            }
            i++;
        }

        return ans;
    
    }
};