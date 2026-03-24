class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==1)return {0};
        int n=nums.size();
        vector<int>pre(n),suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]*nums[i];
        for(int i=n-2;i>=0;i--)suf[i]=suf[i+1]*nums[i];


        vector<int>ans(n);
        for(int i =0;i<n;i++){
            ans[i]=1;
            bool flag=false;
            if(i-1>=0){
                 flag=true;
                ans[i]*=pre[i-1];
            }

            if(i+1<n){
                flag=true;
                ans[i]*=suf[i+1];
            }



        }

        return ans;
        
    }
};