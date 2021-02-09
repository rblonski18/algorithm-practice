// TwoSum - classic. 
// Find two numbers in vector nums that sum to target and return their indices. 
// We iterate through the array and check if the target minus current number
// is in the hashmap (a number we have passed). If it isn't, store the number
// in the hashmap along with it's index. If it is, we grab the index of this 
// number, and our current number's index (i) and return those. If there isn't
// a solution, return empty array. 
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result = {};
        unordered_map<int, int> hashmap; 
        unordered_map<int, int>::iterator it;
        
        for(int i = 0; i < nums.size(); i++) {
            int numToCheck = target - nums[i];
            it = hashmap.find(numToCheck);
            if(it != hashmap.end()) {
                result.push_back(it->second);
                result.push_back(i);
                break;
            } else {
                hashmap[nums[i]] = i;
            }
        }
        return result;
    }
};
