class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int low = 0, high = nums.size() - 1, mid;
        // while (low <= high) {
        //     mid = low + (high - low) / 2;
        //     if (arr[mid] == arr[mid + 1] || arr[mid] == arr[mid - 1]) {
        //         if (arr[mid] == arr[mid + 1] && (high - low + 1) % 2 == 0)
        //             high = mid - 1;
        //         else if (arr[mid] == arr[mid + 1])
        //             low = mid + 2;
        //         else if ((mid - low + 1) % 2 == 0)
        //             low = mid + 1;
        //         else
        //             high = low - 2;
        //     } else
        //         return arr[mid];
        // }
        // return -1;
        int low = 0, high = nums.size() - 1;
        
        while (low < high) { // `low <= high` is unnecessary; single element remains
            int mid = low + (high - low) / 2;

            // Ensure `mid` is even (so mid and mid+1 form a valid pair)
            if (mid % 2 == 1) mid--;

            // Check if the single element is on the right half
            if (nums[mid] == nums[mid + 1])
                low = mid + 2; // Move to the right side
            else
                high = mid; // Move to the left side
        }
        return nums[low];
    }
};