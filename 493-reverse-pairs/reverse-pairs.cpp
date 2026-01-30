class Solution {
public:
    void merge(vector<int>& vec, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftVec(n1), rightVec(n2);

        for (int i = 0; i < n1; i++)
            leftVec[i] = vec[left + i];
        for (int j = 0; j < n2; j++)
            rightVec[j] = vec[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftVec[i] <= rightVec[j])
                vec[k++] = leftVec[i++];
            else
                vec[k++] = rightVec[j++];
        }

        while (i < n1)
            vec[k++] = leftVec[i++];

        while (j < n2)
            vec[k++] = rightVec[j++];
    }

    int countReversePairsInRange(vector<int>& vec, int left, int mid, int right) {
        int count = 0;
        int rightIndex = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (rightIndex <= right &&
                   (long long)vec[i] > 2LL * vec[rightIndex]) {
                rightIndex++;
            }
            count += rightIndex - (mid + 1);
        }
        return count;
    }

    int mergesort(vector<int>& nums, int l, int r) {
        int ct = 0;
        if (l < r) {
            int mid = l + (r - l) / 2;
            ct += mergesort(nums, l, mid);
            ct += mergesort(nums, mid + 1, r);
            ct += countReversePairsInRange(nums, l, mid, r);
            merge(nums, l, mid, r);
        }
        return ct;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};
