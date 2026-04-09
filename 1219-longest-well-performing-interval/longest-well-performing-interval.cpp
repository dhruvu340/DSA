class Solution {
public:
    int longestWPI(vector<int>& hours) {    
        int ans=0;
        map<int,int>m;
        int curr=0;
        for(int i=0;i<hours.size();i++){
            if(hours[i]>8){
                curr++;
            }else{
                curr--;
            }

            if(curr>0){
                ans=i+1;
            }else {
                if(m.find(curr)==m.end()){
                    m[curr]=i;
                }

                if(m.find(curr-1)!=m.end()){
                    ans=max(ans,i-m[curr-1]);
                }
            }
        }

        return ans;
    }
};