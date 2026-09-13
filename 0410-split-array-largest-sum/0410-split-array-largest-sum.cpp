class Solution {
public:
    int canbe(vector<int>& nums, int val){
        int count = 0 , days = 0 , part =1;
        for(int i= 0 ; i< nums.size() ;i++ ){
            if(count + nums[i] <= val) count+=nums[i];
            else part++ , count = nums[i];
        }
        return part;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi = INT_MIN , sum = 0;
        for(auto i: nums) maxi = max(maxi , i) , sum += i;
        int low = maxi , high = sum ;
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low + high)/2;
            int val=canbe(nums,mid);
            if( val<= k) ans = mid , high = mid-1;
            else  low = mid +1;
           
        }
        return ans;
    }
};