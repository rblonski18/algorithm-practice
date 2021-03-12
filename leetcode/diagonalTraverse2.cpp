// diagonally traverse a list of lists -> not necessarily a 
// matrix. Idea is that the sum of indices (row + column) is
// the same for entries on the same diagonal. push entries 
// into a vector in a hashmap, iterate over the vector in 
// reverse, pushing back entries. 


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        vector<int> ans;
        
        unordered_map<int, vector<int>> hash;
        int maxKey = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                hash[i+j].push_back(nums[i][j]);
                maxKey = max(maxKey, i+j);
            }
        }
        
        for(int i = 0; i <= maxKey; i++) {
            for(auto it = hash[i].rbegin(); it != hash[i].rend(); it++) {
                ans.push_back(*it);
            }
        }
        
        
        return ans;
        
    }
};