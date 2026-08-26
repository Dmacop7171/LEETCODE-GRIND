class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> mp; // Stores prefix sum frequencies
        mp[0] = 1; // Base case: A sum of zero occurs once

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // Current prefix sum

            // Check if (sum - k) exists in map
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k]; // Add the frequency of (sum - k)
            }

            // Store prefix sum in map
            mp[sum]++;
        }
        return count;
    }
};
