// Valid Parentheses! 

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses_stack;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                parentheses_stack.push(s[i]);
                continue;
            }
            else if(s[i] == ')') {
                if(parentheses_stack.size() == 0) {
                    return false;
                }
                if(parentheses_stack.top() == '(') {
                    parentheses_stack.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
            else if(s[i] == ']') {
                if(parentheses_stack.size() == 0) {
                    return false;
                }
                if(parentheses_stack.top() == '[') {
                    parentheses_stack.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
            else if(s[i] == '}') {
                if(parentheses_stack.size() == 0) {
                    return false;
                }
                if(parentheses_stack.top() == '{') {
                    parentheses_stack.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        if(parentheses_stack.size() != 0) {
            return false;
        }
        return true;
        
    }
};