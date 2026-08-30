class Solution {
public:
    void merging(vector<int>& nums, int low, int mid, int high) {
        int i = low, j = mid + 1, k = 0;
        vector<int> arr(high - low + 1); // ✅ Allocate space before using

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) arr[k++] = nums[i++];
            else arr[k++] = nums[j++];
        }

        while (i <= mid) arr[k++] = nums[i++];
        while (j <= high) arr[k++] = nums[j++];

        for (int x = low; x <= high; x++) {
            nums[x] = arr[x - low]; // ✅ Correct copying back
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            count += mergeSort(nums, low, mid);
            count += mergeSort(nums, mid + 1, high);
            count += countPairs(nums, low, mid, high);
            merging(nums, low, mid, high);
        }
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
