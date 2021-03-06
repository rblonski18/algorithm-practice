// find the first missing positive in an array
//
// first LC hard problem I solved on my own. 
// solution runs in O(n) time and has constant
// extra space. I really didn't think this was
// much of a hard problem at all



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // the constraint of the problem explains that
        // the length of the vector is at most 300. 
        // this means that the smallest positive missing number
        // is at most 300. I can hold a binary array from 
        // 1 - 300 and as I iterate through, tally which numbers
        // are present. at the end, I iterate through and grab
        // the first missing number. 
        
        vector<int> missingInts(300, 0);
        
        for(int i : nums) {
            if(i > 0 && i < 300) {
                missingInts[i]++;
            }
        }
        
        int missingNum = 0;
        
        for(int j = 1; j < missingInts.size(); j++) {
            if(missingInts[j] == 0) {
                missingNum = j;
                break;
            }
        }
        return missingNum;
    }
};