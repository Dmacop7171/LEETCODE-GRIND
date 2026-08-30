class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sfx = 1, pfx = 1;
        int product = INT_MIN;
       
        for(int i = 0 ; i<nums.size() ; i++){
                 pfx *= nums[i];
                 sfx *= nums[nums.size() - i -1];
                 product = max(product , max(pfx,sfx));
                 if(pfx == 0) pfx=1;
                 if(sfx == 0) sfx=1;
                  
        }
        return product;
    }
};