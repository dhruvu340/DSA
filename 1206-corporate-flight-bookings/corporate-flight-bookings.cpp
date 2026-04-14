class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n,0);
        for(auto i:bookings){
            int st=i[0];
            st--;
            int end=i[1];
            end--;
            int num=i[2];

            diff[st]+=num;
            if(end+1<n){
                diff[end+1]-=num;
            }
        }


        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }


        return diff;

    }
};