class Solution {
public:
    bool check(vector<int>& nums) {
        int key = 0; // Count of order-breaking points
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Check if the current element is greater than the next (cyclically)
            if (nums[i] > nums[(i + 1) % n]) {
                key++;
            }
        }

        // The array is "rotated sorted" if there is at most one break point
        return key <= 1;
    }
};
