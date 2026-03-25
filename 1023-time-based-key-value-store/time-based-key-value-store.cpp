class TimeMap {
public:
    unordered_map<string ,vector<pair<string,int>>>m;
    vector<int>v;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
       if(m.find(key)==m.end())return "";

       int l=0;
       int r=m[key].size();
       string ans="";
       while(l<r){
        int mid = l + (r-l)/2;
        if(m[key][mid].second > timestamp)r=mid;
        else l=mid+1;
       }


        if(l==0)return "";
       return m[key][l-1].first;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */