class Solution {
public:
    bool checkRecord(string s) {
        int absent = count(s.begin(),s.end(),'A');
        
        if(absent<2&&s.find("LLL")==string::npos){
            return true;
        }
        return false;
    }
};