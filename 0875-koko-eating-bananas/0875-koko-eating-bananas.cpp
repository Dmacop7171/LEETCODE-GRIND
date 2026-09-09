class Solution {
public:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        for (int num : v) {
            maxi = max(maxi, num);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int> &v, int hourly) {
        long long totalH = 0;  // Use long long to prevent overflow
        for (int bananas : v) {
            totalH += (bananas + hourly - 1) / hourly;  // Equivalent to ceil(bananas / hourly)
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& v, int h) {  
        int low = 1, high = findMax(v);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(v, mid);  // Use long long

            if (totalH <= h) {
                high = mid - 1;  // Try a smaller speed
            } else {
                low = mid + 1;   // Increase speed
            }
        }
        return low;
    }
};