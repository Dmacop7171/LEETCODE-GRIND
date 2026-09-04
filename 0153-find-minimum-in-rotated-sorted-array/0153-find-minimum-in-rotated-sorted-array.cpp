class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0 , high = arr.size()-1, mid  , mini = INT_MAX;
        while(low <= high){
            mid = low +(high-low)/2;
          if(arr[low] <= arr[mid] && arr[mid] <= arr[high]){   mini = min(mini , arr[low]);break;}

            if(arr[mid] <= arr[high] ) mini = min(arr[mid], mini) , high = mid-1;
            else mini = min(arr[low] , mini), low = mid+1;
        }
        return mini;
    }
};