Quaetion Link -> https://leetcode.com/problems/rotate-image/
Video -> https://www.youtube.com/watch?v=Y72QeX0Efxw&list=PLByG0Le9gW1ukPzWdArXFN8iHh5OgUWOV

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

Approch 1 -> 

use extra matrix, store the first row in the last col of new matrix, and do this for all row

Approch 2->

REVERSE and TRANSPOSE

reverse the matrix and then transpose, watch video for intution.

void rotate(vector<vector<int>>& matrix) {
    //reverse
    reverse(matrix.begin(), matrix.end());
    //transpose
    for(int i=0; i<matrix.size(); i++) {
        for(int j=i; j<matrix.size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
