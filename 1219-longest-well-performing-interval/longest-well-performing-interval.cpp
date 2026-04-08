class Solution {
public:
    int longestWPI(vector<int>& hours) {    
        int ans=0;
        for(int i=0;i<hours.size();i++){
            int curr=0;
            for(int j=i;j<hours.size();j++){
                if(hours[j]>8)curr++;

                if(curr>(j-i+1)/2){
                    ans=max(ans,j-i+1);
                }
            }
        }

        return ans;
    }
};