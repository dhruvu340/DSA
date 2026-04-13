class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ct=0;
        int i=0;
        int j=people.size()-1;
        while(i<=j){
            if(i==j){
                ct++;
                i++;
                j--;
            }else if(people[i]+people[j]<=limit){
                ct++;
                i++;
                j--;
            }else {
                ct++;
                j--;
            }
        }
        return ct;
    }
};