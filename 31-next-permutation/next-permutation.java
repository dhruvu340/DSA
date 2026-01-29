class Solution {
    public void nextPermutation(int[] a) {
        int n = a.length;
        int k;
        for (k = n - 2; k >= 0; k--) {
            if (a[k + 1] > a[k]) {
                break;
            }
        }
        if (k == -1) {
            reverse(a, 0, n - 1);
        } else {
            for (int i = n - 1; i > k; i--) {
                if (a[i] > a[k]) {
                    swap(a, i, k);
                    break;
                }
            }
            reverse(a, k + 1, n - 1);
        }
    }

    private void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private void reverse(int[] a, int start, int end) {
        while (start < end) {
            swap(a, start++, end--);
        }
    }
}