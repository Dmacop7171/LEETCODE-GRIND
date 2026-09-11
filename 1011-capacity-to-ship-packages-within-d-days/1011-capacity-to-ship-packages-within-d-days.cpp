
class Solution {
public:
    int check(vector<int>& weights, int mid) {
        int count = 1, val = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > mid) return INT_MAX; // If a single package is greater than mid, impossible
            if (val + weights[i] <= mid) {
                val += weights[i];
            } else {
                count++;    // New day required
                val = weights[i];
            }
        }
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end()), high = sum, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int comp = check(weights, mid);
            if (comp <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};