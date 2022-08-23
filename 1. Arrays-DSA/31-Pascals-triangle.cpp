Question Link -> https://leetcode.com/problems/pascals-triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Approach -> 

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    res.push_back({1});
    for(int i=1; i<numRows; i++) {
        vector<int> temp;
        temp.push_back(1);
        for(int j=0; j<res[i-1].size()-1; j++) {
            temp.push_back(res[i-1][j] + res[i-1][j+1]); // Add the previous row's above element and diagonal element. 
        }
        temp.push_back(1);
        res.push_back(temp);
    }
    return res;      
}
