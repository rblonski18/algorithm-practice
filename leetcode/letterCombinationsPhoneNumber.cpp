// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
// Return the answer in any order.
//
// my solution was to find the letter combinations recursively 
// from the bottom up (empty -> one number letter combinations
// -> two number letter combinations -> etc.) 
// runtime: O(3^n) -> runs faster than 100% of other LC 
// solutions in C++. 


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // if digits is empty, return an empty vector. 
        
        map<string, string> phone;
        phone["2"] = "abc";
        phone["3"] = "def";
        phone["4"] = "ghi";
        phone["5"] = "jkl";
        phone["6"] = "mno";
        phone["7"] = "pqrs";
        phone["8"] = "tuv";
        phone["9"] = "wxyz";
        
        if(digits == "") return {};
        
        // otherwise, append each letter on the button to 
        // the letters in the list, creating a new vector.
        
        string current;
        if(digits.size() == 1) current = "";
        else current = digits.substr(1, digits.size() - 1); 
        
        // gives string without first character
        
        vector<string> resultVec = letterCombinations(current);
        
        vector<string> newVec = {};
        
        string num(1, digits[0]);
        for(char c : phone[num]) {
             if(resultVec.size() == 0) {
                string str1(1, c);
                newVec.push_back(str1);
            } else {
                for(string s : resultVec) {
                    string res = c + s;
                    newVec.push_back(res);
                }
             }
        }
        
        return newVec;
    }
};
