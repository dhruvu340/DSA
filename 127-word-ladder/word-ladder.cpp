class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordSet(wordList.begin(),wordList.end());
        map<string,vector<string>>adjNeigh;
        int L = beginWord.size();
        for(auto i:wordList){
            for(int j = 0;j<L;j++){
                string s = i.substr(0,j) + "*" + i.substr(j+1,L-j-1);
                adjNeigh[s].push_back(i);
            }
        }

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        wordSet.erase(beginWord);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string front = q.front().first;
                int dist = q.front().second;
                q.pop();
                if(front == endWord){
                    return dist;
                }
                for(int j = 0;j<L;j++){
                string s = front.substr(0,j) + "*" + front.substr(j+1,L-j-1);
                for(auto i:adjNeigh[s]){
                    if(wordSet.find(i)!=wordSet.end()){
                        wordSet.erase(i);
                        q.push({i,dist+1});
                    }
                }
            }
            }
        }
        return 0;

    }
};