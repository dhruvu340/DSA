class Solution {
public:

    int bfs(queue<string>&q,unordered_map<string,int>&stMap,unordered_map<string,int>&endMap,map<string ,vector<string>>&adj){
        int size = q.size();
        while(size--){
            string front = q.front();
            q.pop();
            for(int  i =0;i<front.size();i++){
                string s = front.substr(0,i)+"*"+ front.substr(i+1,front.size()-i-1);
                for(auto j:adj[s]){
                    if(endMap.find(j)!=endMap.end()){
                        return stMap[front] + endMap[j];
                    }

                    if(stMap.find(j)==stMap.end()){
                        q.push(j);
                        stMap[j] = stMap[front] + 1;
                    }
                }
            }
        }
        return 0;
    }
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
        if(wordSet.find(endWord)==wordSet.end())return 0;
        queue<string>st;
        queue<string>end;
        unordered_map<string,int>stMap;
        unordered_map<string,int>endMap;
        stMap[beginWord] = 1;
        endMap[endWord] =1;
        st.push(beginWord);
        end.push(endWord);
        int ans = 0;
        while(!st.empty() && !end.empty()){
            if(st.size() <= end.size()){
                ans = bfs(st,stMap,endMap,adjNeigh);
            }else{
                ans = bfs(end,endMap,stMap,adjNeigh);
            }
            if(ans!=0)return ans;
        }

        return ans;
    }
};