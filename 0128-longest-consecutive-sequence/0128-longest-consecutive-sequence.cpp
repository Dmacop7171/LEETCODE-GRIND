class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
  
        if (nums.empty()) return 0; // Edge case: If nums is empty, return 0

        set<int> s(nums.begin(), nums.end()); // Insert all elements into a set
        int maxStreak = 0;

        for (int num : s) {
            // Check if num is the start of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Count the length of the consecutive sequence
                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    currentStreak++;
                }

                maxStreak = max(maxStreak, currentStreak);
            }
        }
        return maxStreak;
    }
};