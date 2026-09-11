class Solution {
public:
    int bloom(vector<int>& arr, int mid , int k){
            int count = 0 , value = 0;
            for(auto i: arr){
                if(i <= mid){
                    value++;
                    if(value == k) count++, value=0;
                }else value = 0;
            }
            return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
     if ((long long) m * k > bloomDay.size()) return -1;

        int maxi = INT_MIN, mini = INT_MAX;
        for(auto i: bloomDay){
            maxi = max(maxi , i);
            mini = min(mini , i);
        }
        int low = mini , high = maxi , ans=-1;;
        while(low <= high){
            int mid = low + (high - low)/2;
            int comp = bloom(bloomDay , mid , k);
            if(comp >= m){
                ans = mid;
                high = mid-1;
            }else low = mid + 1;
        }
        return ans;
    }
};