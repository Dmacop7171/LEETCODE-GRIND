class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> s;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue; // Skip duplicate elements
            
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    s.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate elements for `j` and `k`
                    while (j < k && nums[j] == nums[j - 1]) 
                        j++;
                    while (j < k && nums[k] == nums[k + 1]) 
                        k--;
                }
            }
        }
        return s;
    }
};