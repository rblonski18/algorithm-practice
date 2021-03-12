// hand of straights - rearrange cards into groups
// of size W, consisting of W consecutive cards. 
// 
// idea is to grab counts of each num and put
// into has map. iterate over hashmap, saying:
// if count of this number > 0, for i -> W, 
// subtract the number of instances I have of this
// card. the entries in the hash cannot be less than
// zero after this operation. 


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        
        map<int, int> hash;
        
        for(int num : hand) hash[num]++;
        
        for(auto it : hash) {
            if(hash[it.first] > 0) {
                for(int i = W-1; i >= 0; --i) {
                    if((hash[it.first+i] -= hash[it.first]) < 0) {
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};