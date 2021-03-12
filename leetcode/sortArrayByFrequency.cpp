// sort array by increasing frequency
// 
// grab frequency counts and run a custom sort -> 
// if same counts, put smaller number first, else put
// number with lower frequency first. 


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> counts;
        
        for(int num : nums) {
            counts[num]++;
        }
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
           return counts[a] == counts[b] ? a > b : counts[a] < counts[b]; 
        });
            
        
        return nums;
    }
};