// group alike anagrams together into a vector of vectors. 
//
// solution: hold a hashmap of character counts to result
// vector index of vector holding anagrams with the same
// character counts. for each string, find the character count,
// see if that character count is already in the hashmap. if so, 
// append the current string to the vector at index specified
// by the hashmap. otherwise, create a new entry with that 
// charcount in the hashmap and append a new vector to the result
// , the size of the resulting vector before append
// is the index of our new vector -> make that the latter of the
// key-value pair. 


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // O(n) -> hashmap with index & charCount array. 
        
        if(strs.size() == 0) return {{}};
        
        map<vector<int>, int> hashMap;
        vector<vector<string>> result;
        
        for(string str : strs) {
            
            vector<int> charCounts(26, 0);
            for(char c : str) {
                charCounts[c-97]++;
            }
            
            if(hashMap.find(charCounts) != hashMap.end()) {
                int vecIndex = hashMap[charCounts];
                result[vecIndex].push_back(str);
            } else {
                int resSize = result.size();
                vector<string> newCount;
                newCount.push_back(str);
                result.push_back(newCount);
                hashMap[charCounts] = resSize;
            }
            
        }
        
        return result;
        
    }
};