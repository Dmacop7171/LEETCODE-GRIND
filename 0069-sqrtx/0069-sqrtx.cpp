class Solution {
public:
    int mySqrt(int n) {
        long long int low = 0, high = n,mid=0 ,ans;
    while(low <= high){
        mid = low + (high - low)/2;
       if(mid * mid <= n ) ans = mid , low =mid+1;
       else high = mid-1;
    }
    return ans;
    }
};