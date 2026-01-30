class Solution {
public:
void merge(vector<int>& nums,int l,int mid,int r){
    vector<int>temp;
    int i=l;
    int j=mid+1;
    while(i<=mid&&j<=r){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j++]);
        }
    }

    while(i<=mid){
         temp.push_back(nums[i++]);
    }


    while(j<=r){
        temp.push_back(nums[j++]);
    }

    for(int i=0;i<temp.size();i++){
        nums[i+l]=temp[i];
    }

}


int countpair(vector<int>& nums,int l,int mid,int r){
    int ct=0;
    int j=mid+1;
    for(int i=l;i<=mid;i++){
        while(j<=r&&(nums[i]>(2LL*nums[j]))){j++;}
        ct+=j-(mid+1);
    }
    return ct;
}
    int mergesort(vector<int>& nums,int l,int r){
        int ct=0;
        if(l<r){
            int mid=l+(r-l)/2;
           ct+= mergesort(nums,l,mid);
           ct+= mergesort(nums,mid+1,r);
           ct+= countpair(nums,l,mid,r);
           merge(nums,l,mid,r);
        }

        return ct;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
      return  mergesort(nums,0,n-1);
    }
};