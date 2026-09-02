class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;  // Default to 'n' if no element is >= x

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] >= x) {  
            ans = mid;   // Update upper bound index
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;  // Return the 0-based index


    }
};