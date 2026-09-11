class Solution {
public:
    int div(vector<int>& nums , int mid){
        int count = 0;
        for(auto i: nums){
                count += ceil((double)i/ (double)mid);
        }
        return count;
        
    }
    int maximum(vector<int> v){
        int maxi = INT_MIN;
        for(auto i:v) maxi = max(maxi , i);
        return maxi;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 , high = maximum(nums ) , ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int val = div(nums , mid);
            if(val <= threshold)   high = mid-1 , ans = mid;
            else low = mid+1;
        }
        return ans;
    }
};