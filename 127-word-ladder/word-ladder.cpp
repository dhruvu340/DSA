class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            int level = q.size();
            while(level--){
                string topSt =  q.front().first;
                int count  = q.front().second;
                q.pop();
                if(topSt == endWord)return count; 
                for(int i = 0;i<beginWord.size();i++){
                    char orig = topSt[i];
                    for(char alpha = 'a';alpha<='z';alpha++){
                        topSt[i] = alpha;
                        if(s.find(topSt)!=s.end()){
                            s.erase(topSt);
                            q.push({topSt,count+1});
                        }
                    }
                    topSt[i] = orig; 
                }
            }
        }

        return 0;
    }
};