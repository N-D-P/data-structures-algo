Question Link -> https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n integer matrix matrix, 
if an element is 0, set its entire row and column to 0's.

Approach 1 -> brute force

If zero is encountered while traversing, then mark all the elements of that row and col as -1 
except 0 cause that zero will be later used to mark its row and col.

Approach 2 -> better 

Take two array, one of size row and other of size column
While traversing matrix if zero is encountered then mark its row number and column as zero in 
those given two array 
While traversing again the matrix make the elements as zero whose row number column 
number has been marked

Approach 3 -> best

Instead of taking 2 different array use the first row and col as a marking arrays.

void setZeroes(vector<vector<int>>& matrix) {
    bool row0=false,col0=false;
    int r=matrix.size(),c=matrix[0].size();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(matrix[i][j]==0)
            {
                if(i==0) row0 = true; // If zero is encountered in first row/col
                if(j==0) col0 = true; // This will used to make tht row/col complete zero
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(matrix[i][0]==0||matrix[0][j]==0)
                matrix[i][j]=0;
        }
    }
    if(row0)
        for(int i=0;i<c;i++)
            matrix[0][i]=0;
    if(col0)
        for(int j=0;j<r;j++)
            matrix[j][0]=0;
}
