
Big idea:
1. Thought of using BInary Search
2. mid/c gives ROW and mid%c gives coloumn

    bool searchMatrix(vector<vector<int>>& matrix, int target)     {
        if(matrix.size()==0) return false;
        int r=matrix.size(),c=matrix[0].size();
        int low=0,high=(r*c)-1,mid;
        
        while(low<=high)
        {
            mid = (low + (high-low)/2);
            if(matrix[mid/c][mid%c] == target)
                return true;
            else if(matrix[mid/c][mid%c] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        return false;
    }


*Without binary search*

Big Idea:
1. Find row number of target<=mat from last colomn
2. search in that row

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool find=false;
        int rowN = 0;
        int r = matrix.size();
        int c = matrix[0].size();
        
        if(target < matrix[0][0] || target > matrix[r-1][c-1])
            return false;
        
        for(int i=0;i<r;i++)
            if(target <= matrix[i][c-1])
            {
                find=true,rowN=i;
                break;
            }
        
        if(find)
            for(int j=0;j<c;j++)
                if(target == matrix[rowN][j])
                    return true;
        
        return false;
    }
