class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n=v.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&v[st.top()]>v[i]){
                int el=v[st.top()];
                st.pop();
                int nse = i ;
                int pse = (st.empty()) ?  -1 : st.top();
                ans=max(ans,(el*(nse-pse-1)));

            }
            st.push(i);

        }

         while(!st.empty()){
                int el=v[st.top()];
                st.pop();
                
                int pse = (st.empty()) ?  -1 : st.top();
                ans=max(ans,(el*(n-pse-1)));

            }


        return ans;
        

    }
};