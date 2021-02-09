// Chapter one of CTCI is simple but that's the point. Helps emphasize 
// fundamentals of making the problem trivial through use of a certain
// data structure or sorting. 


// Problem statement - 1.1: 
// Implement an algorithm to determine if a string has all unique characters 
//
// Just use a hash table to hold previously used characters. If we come across
// a character that is already in the hash table -> not unique. 

class Solution1_1 {
public:
	bool uniqueCharacters(string word) {
		unordered_set<char> hashTable; 
		for(char c : word) {
			if(hashTable.find(c) != hashTable.end()) return false;
			else hashTable.insert(c);
		}
		return true;
	}
}

// 1.1 continued: what if you can't use additional data structures ? 

// sort the characters in the string. If the characters are sorted, 
// any non-unique letters will be adjacent. I just sort the string
// and iterate through, checking if the current letter and the next
// are the same.
// time complexity: O(n log n) runtime (merge/insertion sort of c++ sort())
// space complexity: O(1);

class Solution1_1NoDS {
public:
	bool uniqueCharactersNoDS(string word) {
		sort(word.begin(), word.end());
		for(int i = 0; i < word.size()-1; i++) {
			if(word[i] == word[i+1]) return false;
		}
		return true;
	}
}

// 1.2 - Given two strings, write a method to determine if one
// is a permutation of the other. 

// A simple way to do this is to hold an array of character 
// counts for both strings, and then loop through these to check
// if they're the same. 

class Solution1_2 {
public: 
	bool stringPermutation(string str1, string str2) {
		int charCount1[26];
		int charCount2[26];

		for(char c : str1) {
			charCount1[c-97]++;
		}

		for(char c : str2) {
			charCount2[c-97]++;
		}

		for(int i = 0; i < 26; i++) {
			if(charCount1[i] != charCount2[i]) return false;
		}

		return true;
	}
}