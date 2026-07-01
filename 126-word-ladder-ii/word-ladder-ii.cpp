class Solution {
public:
    unordered_map<string ,vector<string>>adj;
    vector<string>curr;
    vector<vector<string>>ans;

    vector<string> findneg(string &word,unordered_set<string>&s){
        vector<string>neg;
        for(int i = 0;i<word.size();i++){
            char old = word[i];
            for(char c='a';c<='z';c++){
                word[i] = c;
                if(c==old||!s.count(word)){
                    continue;
                }
                neg.push_back(word);

            }
            word[i] = old;
        }

        return neg;
    }
    void backtrack(string &src,string &dest){
        if(src == dest){
            ans.push_back(vector<string>(curr.rbegin(),curr.rend()));
        }

        for(int i = 0;i<adj[src].size();i++){
            curr.push_back(adj[src][i]);
            backtrack(adj[src][i],dest);
            curr.pop_back();
        }
    }
    void bfs(string beginWord,string endWord,unordered_set<string>&s){
        queue<string>q;
        q.push(beginWord);
        if(s.find(beginWord)!=s.end()){
            s.erase(beginWord);
        }
        unordered_map<string,int>enqueued;
        enqueued[beginWord]=1;
        while(!q.empty()){
            vector<string>vis;
            int size = q.size();
            while(size--){
                string currWord = q.front();
                q.pop();
                vector<string>neg = findneg(currWord,s);
                for(auto i:neg){
                    vis.push_back(i);
                    adj[i].push_back(currWord);
                    if(enqueued.find(i)==enqueued.end()){
                        q.push(i);
                        enqueued[i] = 1;
                    }
                }
            }

            for(int i = 0;i<vis.size();i++){
                if(s.find(vis[i])!=s.end()){
                    s.erase(vis[i]);
                }
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        bfs(beginWord,endWord,s);
        curr = {endWord};
        backtrack(endWord,beginWord);
        return ans;
    }
};