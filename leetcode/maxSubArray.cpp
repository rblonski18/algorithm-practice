// a simple solution to the maxSubArray problem
// 
// the idea is to keep track of local max. 
// is my current max plus the next element
// bigger than the next element? if so, 
// go ahead and add it on. If not, don't 
// update global max as you go on


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int previousMax = nums[0];
        int currentMax = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            previousMax = max(previousMax + nums[i], nums[i]);
            currentMax = max(currentMax, previousMax);
        }
        return currentMax;
    }
};