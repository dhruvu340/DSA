class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int sizeOfString = beginWord.size();
        set<string>lookup(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        lookup.erase(beginWord);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string word = q.front().first;
                int seqSize = q.front().second;
                q.pop();
                if(word == endWord)return seqSize;

                for(int i=0;i<sizeOfString;i++){
                    char orig = word[i];
                    for(char c='a';c<='z';c++){
                        word[i] = c;
                        if(lookup.find(word)!=lookup.end()){
                            q.push({word,seqSize+1});
                            lookup.erase(word);
                        }
                    }
                    word[i] = orig;
                }
            }
        }
        return 0;
    }
};