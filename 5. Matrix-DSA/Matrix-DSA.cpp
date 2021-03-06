Matrix-DSA

1-> Spiral matrix 
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0, top=0;
        int right=matrix[0].size()-1,bottom=matrix.size()-1;
        vector<int> result;
        while(left<=right && top<=bottom)
        {
            for(int i=left;i<=right;i++)
                result.push_back(matrix[top][i]);
            top++;
            for(int i=top;i<=bottom;i++)
                result.push_back(matrix[i][right]);
            right--;
            if(top<=bottom)
            for(int i=right;i>=left;i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
            if(left<=right)
            for(int i=bottom;i>=top;i--)
                result.push_back(matrix[i][left]);
            left++;
        }
        return result ;
    }

2->Search in 2D matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int left = 0;
        int right = (matrix.size()*matrix[0].size())-1;
        int c = matrix[0].size();
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(matrix[mid/c][mid%c] == target)
                return true;
            else if(matrix[mid/c][mid%c] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return false;
    }

3-> Median in a row wise sorted array 

//Median is the middle element of a sorted array

int binaryMedian(int m[][MAX], int r ,int c) 
{ 
	int min = INT_MAX, max = INT_MIN; 
	for (int i=0; i<r; i++) 
	{ 
		// Finding the minimum element 
		if (m[i][0] < min) 
			min = m[i][0]; 

		// Finding the maximum element 
		if (m[i][c-1] > max) 
			max = m[i][c-1]; 
	} 

	int desired = (r * c + 1) / 2; 
	while (min < max) 
	{ 
		int mid = min + (max - min) / 2; 
		int place = 0; 

		// Find count of elements smaller than mid 
		for (int i = 0; i < r; ++i) 
			place += upper_bound(m[i], m[i]+c, mid) - m[i]; 
		if (place < desired) 
			min = mid + 1; 
		else
			max = mid; 
	} 
	return min; 
} 

 

5-> Sorted Matrix

    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> Mat) {
        // code here
        vector<int> data;
        int k=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                data.push_back(Mat[i][j]);
        
        sort(data.begin(),data.end());
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            { 
                Mat[i][j] = data[k];
                k++;
            }
                
        return Mat;
    }

6-> Maximal Rectangle (Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.)

    Video Link-> https://www.youtube.com/watch?v=g8bSdXCG-lA
    Question Link -> https://leetcode.com/problems/maximal-rectangle/

    1. Take a array(hist) of size of row
    2. Loop from first row(each column)
    3. if matrix[i][j] == 0, 
            then make hist[j] = 0
    else
            make hist[j] += matrix[i][j]
    4. Send hist to largestRectangleArea() function (Found explanation in Array q15)
    5. largestRectangleArea() will return area of that histogram, compare with maxarea and Update maxarea accordinly 

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0; // for edge case of empty matrix
        
        vector<int> row(matrix[0].size());

        for(int j=0;j<matrix[0].size();j++)
            row[j] = matrix[0][j];
        
        int area = largestRectangleArea(row);
        int maxarea = area>maxarea?area:maxarea;
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 1)
                {
                    row[j] += matrix[i][j];
                }
                else 
                {
                    row[j] = 0;
                }
               
            }
            area = largestRectangleArea(row);
            maxarea = area>maxarea?area:maxarea;
        }
        return maxarea;
    }