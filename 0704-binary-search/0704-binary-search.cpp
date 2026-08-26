class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = nums.size()/2 , low = 0 , high  = nums.size()-1;
        while(low <= high){
            if(nums[mid] == target ) return mid;
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
            mid = (low + high)/2;
        }
        return -1;
    }
};