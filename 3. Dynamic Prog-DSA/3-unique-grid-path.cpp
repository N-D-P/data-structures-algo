Question -> https://leetcode.com/problems/unique-paths/
Video -> striver 
Solution -> https://leetcode.com/problems/unique-paths/discuss/1581998/C%2B%2BPython-5-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Math

Question There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Apprach 1 -> recurrsion 

Recurse every path from start to end, which can be achieved by moving down and right.
At each cell we can either move down or move right.
Choosing either of these moves could lead us to an unique path
So we consider both of these moves.
If the series of moves leads to a cell outside the grid's boundary, we can return 0 denoting no valid path was found.
If the series of moves leads us to the target cell (m-1, n-1), we return 1 denoting we found a valid unique path from start to end.

class Solution {
public:
    int uniquePaths(int m, int n, int i = 0, int j = 0) {
        if(i >= m || j >= n) return 0;                                    // reached out of bounds - invalid
        if(i == m-1 && j == n-1) return 1;                                // reached the destination - valid solution
        return uniquePaths(m, n, i+1, j) + uniquePaths(m, n, i, j+1);     // try both down and right
    }
}; 

Approach 2 -> DP 




