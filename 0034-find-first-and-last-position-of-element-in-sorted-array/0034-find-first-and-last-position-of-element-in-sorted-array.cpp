class Solution {
public:
int lower(vector<int>& nums, int target){
    int low = 0, high = nums.size()-1;
    int ans = nums.size() ;
    while(low<=high){
        int mid = low + (high - low )/2;
        if(nums[mid] == target) ans = mid , high = mid-1;
        else if(nums[mid] < target) low = mid+1;
        else high = mid -1;
    } 
    return ans;
}
int upper(vector<int>& nums, int target){
    int low = 0, high = nums.size()-1;
     int ans = nums.size() ;
    while(low<=high){
        int mid = low + (high - low )/2;
        if(nums[mid] == target) ans = mid ,low = mid+1;
        else if(nums[mid] > target) high = mid -1;
        else low = mid+1;
    } 
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower(nums , target);
        if(lb == nums.size()  || nums[lb] != target) return {-1,-1};
        return {lb , upper(nums,target)};
    }
};