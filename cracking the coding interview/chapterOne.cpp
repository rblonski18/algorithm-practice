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

// 1.3 - Given some string, write a method to replace all spaces
// with "%20" -> URLify. Assume adequate space for added characters
// is already in the back of the string. 
//
// We pass through the string once to determine the number of spaces
// in the string. After determining this, we can find out how long 
// our new string must be. We parse through the string back to front, 
// and assign letters from their old string into positions of their 
// new string 
// Time complexity: O(n)
// Space complexity: O(1)

class Solution1_3 {
public:
	string urlify(string toURL) {
		int spaces = 0;
		
		for(int i = 0; i < toURL.size(); i++) {
			if(str[i] == ' ') spaces++;
		}

		int index = toURL.size() + (spaces*2); // # of extra characters from buffer needed. 
		for(int j = toURL.size()-1; j >= 0; j--) {
			if(str[i] == ' ') {
				str[index-1] = '0';
				str[index-2] = '2';
				str[index-3] = '%';
				index = index - 3;
			} else {
				str[index-1] = str[j];
				index--;
			}
		}
	}
}

// 1.4 - given a string, write a method to determine if it
// is a permutation of a palindrome. 
//
// The idea is to store an array of letter counts. We only 
// need to check if the letters could make up a palindrome. 
// There must either be an even number of each letter, or
// a single count of an odd number of a certain letter, 
// and the rest even letters. 

class Solution1_4 {
public: 
	bool isPermutationOfPalindrome(string word) {

		int charCount[26];
		bool passedOdd = false;

		for(char c : word) {
			charCount[c-97]++;
		}

		for(int i = 0; i < 26; i++) {
			if(charCount[i] % 2 != 0) {
				if(passedOdd) return false;
				else passedOdd = true;
			}
		}
		return true;
	}
}

