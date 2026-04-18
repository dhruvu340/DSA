class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans =0 ;
        int n=maxHeights.size();
        vector<long long>left(n,0),right(n,0);
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++){
            int maxi = maxHeights[i];
            long long ct;
            while(!s.empty()&&maxi<=s.top().first){
                
                s.pop();
            }
            

            if(s.empty()){

               ct=maxi*1LL*(i+1);
            }else{
                ct=maxi*1LL*(i - s.top().second) + left[s.top().second];
            }

            s.push({maxi,i});

            left[i]=ct;
        }

        while(!s.empty())s.pop();

        for(int i=n-1;i>=0;i--){
           int maxi = maxHeights[i];
           long long ct;
            while(!s.empty()&&maxi<=s.top().first){
                
                s.pop();
            }
            

            if(s.empty()){

               ct=maxi*1LL*(n-i);
            }else{
                ct=maxi*1LL*(abs(i - s.top().second)) + right[s.top().second];
            }

            s.push({maxi,i});

            right[i]=ct;
        }


        for(int i=0;i<n;i++){
            ans=max(ans,left[i]+right[i]-maxHeights[i]);
        }
        return ans;

    }
};