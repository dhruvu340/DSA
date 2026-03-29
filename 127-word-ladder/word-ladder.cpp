class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({begin,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string word=q.front().first;
                int steps=q.front().second;
                q.pop();
                if(word==end)return steps;
                for(int i=0;i<word.size();i++){
                    char orig=word[i];
                    for(char c='a';c<='z';c++){
                        word[i]=c;
                        if(s.find(word)!=s.end()){
                            s.erase(word);
                            q.push({word,steps+1});
                        }
                    }
                    word[i]=orig;
                }

            }
        }

        return 0;
    }
};