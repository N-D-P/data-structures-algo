/**
 * Question Link -> https://leetcode.com/problems/merge-sorted-array/
 * 
 * Explanation ->
 *  The way to think about the solution is that we will have to do a reverse sorting.
    We initialize k=m+n-1 as that will be the last location of nums1.
    We will keep checking for the greater element of the two arrays(i=m-1,j=n-1) and insert the values.
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    nums1 = [1,2,3,0,0,0]
                |     |
                i     k

    nums2 = [2,5,6]
                |
                j
    nums2[j]>nums1[i] thus nums1[k]=6
    k and j are decremented.

    nums1 = [1,2,3,0,0,6]
                |     |
                i     k

    nums2 = [2,5,6]
            |
            j
    nums2[j]>nums1[i] thus nums1[k]=5
    k and j are decremented.

    nums1 = [1,2,3,0,5,6]
                |   |
                i   k

    nums2 = [2,5,6]
            |
            j
    We keep following up this procedure and we get the desired result.
*/

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 and j>=0) {
            if(nums2[j] >= nums1[i]) {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
            else {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }
        
        while(i >= 0) {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }

/*      ****GeeksForGeeks****
 * Question Link -> https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
 * Video Link -> https://www.youtube.com/watch?v=hVl2b3bLzBw
 */

    // Function to find next gap.
    int nextGap(int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }
    
    void merge(int* arr1, int* arr2, int n, int m)
    {
        int i, j, gap = n + m;
        for (gap = nextGap(gap);
            gap > 0; gap = nextGap(gap))
        {
            // comparing elements in the first array.
            for (i = 0; i + gap < n; i++)
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);
    
            // comparing elements in both arrays.
            for (j = gap > n ? gap - n : 0;
                i < n && j < m;
                i++, j++)
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);
    
            if (j < m) {
                // comparing elements in the second array.
                for (j = 0; j + gap < m; j++)
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
            }
        }
    }