// this is the solution from Nick White's video,
// I think it's way more intuitive than a lot
// of the DP solutions i've seen. 
//
// Idea is to grab each letter and treat it as if
// it were a possible middle or left-of-middle letter
// within a palindrome, checking if letters on left
// equal letters on right. If it is, return the length


class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s == "" || s.size() < 1) return 0;
        
        int start = 0;
        int end = 0;
        
        for(int i = 0; i < s.size(); i++) {
            int len1 = expandFromMiddle(s, i, i);
            int len2 = expandFromMiddle(s, i, i+1);
            int maxLen = max(len1, len2);
            if(maxLen > (end-start)) {
                start = i - ((maxLen-1) / 2);
                end = i + (maxLen / 2);
            }
        }
        
        return s.substr(start, (end-start)+1);
        
    }
    
    int expandFromMiddle(string s, int left, int right) {
        
        if(s == "" || left > right) return 0;
        
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1;
        
        
    }
};