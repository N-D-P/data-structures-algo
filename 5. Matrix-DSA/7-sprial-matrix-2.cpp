// Question Link -> https://leetcode.com/problems/spiral-matrix-ii/

//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

    vector<vector<int>> generateMatrix(int n) {
        int sq=1;
        vector<vector<int>> res(n,vector<int>(n));
        int left = 0,right=n-1,top=0,bottom=n-1;
        while(left<=right or top<=bottom)
        {
            for(int i=left; i<=right; i++)
                res[top][i] = sq++;
            top++;
            for(int j=top; j<=bottom; j++)
                res[j][right] = sq++;
            right--;
            for(int i=right;i>=left;i--)
                res[bottom][i] = sq++;
            bottom--;
            for(int j = bottom;j>=top;j--)
                res[j][left] = sq++;
            left++;
        }
        return res;
    }