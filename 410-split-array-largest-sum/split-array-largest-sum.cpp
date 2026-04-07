class Solution {
public:
int counts(vector<int>&a,int x){
    int students=1;
    long long pages=0;
    for(int i=0;i<a.size();i++){
        if(pages+a[i]<=x){
            pages+=a[i];
        }else{
            pages=a[i];
            students++;
        }
    }
    return students;
}
    int splitArray(vector<int>& nums, int k) {

        if(nums.size()<k){
            return -1;
        }

        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0,[](int a,int b){
            return a+b;
        });

        while(l<r){
            int mid= l+(r-l)/2;
            int st=counts(nums,mid);
            if(st<=k){r=mid;}
            else{
                l=mid+1;
            }
        }

        return l;

        
    }
};