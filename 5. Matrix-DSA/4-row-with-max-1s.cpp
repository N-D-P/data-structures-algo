4-> Row with max 1s
    4.1-> Binary search on each row
        int first(vector<int> arr,int l,int r)
        {
            while(l<=r)
            {
                int mid = (l+r)/2;
                if((arr[mid-1]==0) and (arr[mid]==1)) // condition for finding first one
                    return mid;
                else if(arr[mid]==0)
                    l=mid+1;
                else
                    r=mid-1;
            }
            return -1;
        }
        int rowWithMax1s(vector<vector<int> > arr, int r, int c) {
            // code here
            int index=0,res=-1,maxsum=INT_MIN;
            for(int i=0;i<r;i++)
            {
            index = first(arr[i],0,c-1);
            if(index!=-1&&c-index > maxsum)
            {
                res = i;
                maxsum = c-index;
            }
            }
            return res;
        }

    4.2->
    // The main function that returns index of row with maximum number of 1s.
    int rowWithMax1s(bool mat[R][C])
    {
        // Initialize first row as row with max 1s
        int max_row_index = 0;

        // The function first() returns index of first 1 in row 0.
        // Use this index to initialize the index of leftmost 1 seen so far
        int j = first(mat[0], 0, C-1);
        if (j == -1) // if 1 is not present in first row
        j = C - 1;

        for (int i = 1; i < R; i++)
        {
            // Move left until a 0 is found
            while (j >= 0 && mat[i][j] == 1)
            {
                j = j-1; // Update the index of leftmost 1 seen so far
                max_row_index = i; // Update max_row_index
            }
        }
        return max_row_index;
    }