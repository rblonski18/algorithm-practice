// given an array of integers, what's the length of the 
// longest arithmetic subsequence in A? For example:
// [3, 6, 9, 12] should return four, because there is
// an arithmetic subsequence (of numBefore + 3) of length
// four
//
// the idea is a standard dynamic programming solution. 
// each entry in the matrix is the longest arithmetic 
// subsequence up to that point of difference A[j] - A[i].
// the rows in the matrix are the values in A, and the 
// columns are the difference. keep track of max entry in
// the matrix. 
//
// the +1000 is to compensate for the constraints given. 
// A.length <= 1000. 

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        
        int res = 2;
        int n = A.size();
        
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int d = A[j] - A[i] + 1000;
                dp[j][d] = max(2, dp[i][d]+1);
                res = max(res, dp[j][d]);
            }
        }
        
        return res;
    }
};