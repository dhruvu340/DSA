class Solution {
public:
    double bfs(unordered_map<string,vector<pair<string,double>>>&m,string src,string target){
        if(m.find(src)==m.end())return -1;
        queue<pair<string,double>>q;
        q.push({src,1});
        set<string>vis;
        vis.insert(src);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string u = q.front().first;
                double w = q.front().second;
                q.pop();
                if(u == target)return w;
                for(auto i:m[u]){
                    if(vis.find(i.first)==vis.end()){
                        vis.insert(i.first);
                        q.push({
                            i.first,
                            i.second * w
                        });
                    }
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<pair<string,double>>>m;
        int n=equations.size();
        for(int i = 0 ;i < n;i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double weight = values[i];

            m[u].push_back(make_pair(v,weight));
            m[v].push_back(make_pair(u,1.0/weight));
        }

        int t = queries.size();
        vector<double>ans;
        for(auto i:queries){
            string u = i[0];
            string v = i[1];
            double ansto = bfs(m,u,v);
            ans.push_back(ansto);
        }
        return ans;
    }
};