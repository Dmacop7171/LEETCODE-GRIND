#include <climits>  // Include this to use INT_MIN

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0 , count2=0;
        int ele1,ele2;
        ele1 = ele2 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if((count1 == 0 ) && (nums[i] != ele2)) count1=1, ele1=nums[i];
            else if((count2 == 0 ) && (nums[i] != ele1)) count2=1, ele2=nums[i];
            else if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;
            else count1--,count2--;
        }
        count1=count2=0;
        for(auto i:nums){
            if(i == ele1) count1++;
            if(i == ele2) count2++;
        }
        vector<int> ls;
        int mini = (int)(nums.size()/3)+1;
        if(count1 >= mini) ls.push_back(ele1);
        if(count2 >= mini) ls.push_back(ele2);
        sort(ls.begin() , ls.end());
        return ls;
    }
};