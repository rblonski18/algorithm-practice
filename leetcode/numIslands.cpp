/* you are given a 2d array of ones and zeros as follows:

[
[0, 0, 0, 0, 1],
[0, 0, 1, 0, 1],
[1, 1, 1, 0, 0],
[1, 1, 0, 0, 1],
[0, 0, 0, 0, 0]
]

Islands are groupings of ones - two ones are in the same 
grouping if they are to the left, right, above, or below
one another, diagonals don't count. Question is: how
many islands are there?

Solution: iterate over 2d array, and run bfs each time you
 hit a one -> bfs function flips it's current value to zero,
 and calls itself recursively on any squares that are also on
 the same island. as a result, you increment your numislands
 counter by one, and you've eliminated the entire island from
 your matrix. repeat until end of matrix. 
*/



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int numIslands = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    numIslands++;
                    bfs(i, j, grid);
                }
            }
        }
        return numIslands;
    }
    
    void bfs(int row, int column, vector<vector<char>>& grid) {
        
        if(grid[row][column] == '0') return;
        else grid[row][column] = '0';
        
        // up
        if(row > 0) bfs(row-1, column, grid);
        
        // left
        if(column > 0) bfs(row, column-1, grid);
        
        // down
        if(row < grid.size()-1) bfs(row+1, column, grid);
        
        // right
        if(column < grid[0].size()-1) bfs(row, column+1, grid);
        
        
        
    }
};