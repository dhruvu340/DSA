class Solution {
public:
void merge(vector<int>& vec, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    vector<int> leftVec(n1), rightVec(n2);

    // Copy data to temporary vectors
    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    // Merge the temporary vectors back into vec[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftVec[], if any
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightVec[], if any
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}


int countpair(vector<int>& vec, int left, int mid, int right){
    int ct=0;
    int right1=mid+1;
    for(int i=left;i<=mid;i++){
        while(right1<=right&&(vec[i]>2LL*(vec[right1]))){right1++;}
        ct+=right1-(mid+1);
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