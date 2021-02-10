// In a string, find the longest substring without
// repeating characters. 
//
// The main idea behind the algorithm is called the "sliding
// window" technique - we hold a hashmap containing letters 
// currently in our hashmap, and take two pointers, left and 
// right, moving them along like a sliding window. If we find a 
// duplicate letter, move left pointer past the first instance 
// of whichever letter this is. 

class Solution {
public:
	int longestSubtring(string word) {
		int longest = 0;
		if(word.size() == 0) return 0;

		map<char, int> hashmap;

		for(int i = 0, j = 0; i < word.size(); i++) {
			if(hashmap.find(word[i]) != hashmap.end()) {
				j = max(j, hashmap[word[i]]+1);
			}
			hashmap[word[i]] = i;
			longest = max(longest, i-j+1);
		}
		return longest;
	}
}