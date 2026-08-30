class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, susq = 0; // Use long long for large sums
        int row = grid.size();
        long long n = row * row; // Ensure n is long long

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                sum += grid[i][j];
                susq += (1LL * grid[i][j] * grid[i][j]); // Ensure no overflow
            }
        }

        long long expectedSum = (n * (n + 1)) / 2;
        long long expectedSqSum = (n * (n + 1) * (2 * n + 1)) / 6;

        long long x = sum - expectedSum;    // r - m
        long long y = susq - expectedSqSum; // r^2 - m^2

        long long r = (x + (y / x)) / 2;  // r = (diff + ratio) / 2
        long long m = r - x;              // m = r - diff

        return {(int)r, (int)m}; // Convert back to int safely
    }
};
