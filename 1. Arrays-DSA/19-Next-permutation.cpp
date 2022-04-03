/*
 * Question Link -> https://leetcode.com/problems/next-permutation/
 * Video Link -> https://youtu.be/LuLCLgMElus?t=222
 * 
 * Explation ->
 * 
 * There will be always an increasing sequence from the back side of dictionary numbers 
 * for eg. 1 5 3 6 4 2   
 *
 *        1 5 3 6
 *                4 
 *                  2
 *  So we must be able to change/increase the prefix i.e. 1 5 3, in order to get next permutation
 *  Swap 3 which is the brk out point with the number that is just greater then 3 while traversing from right, 
 *  we can replace 1 5 3 with 1 5 6 but it would not give us next permutation, so we replace 1 5 3 with 1 5 4,
 *          1 5 4 6
 *                 3 
 *                  2
 *  
 *  Now we have to take care of 6 3 2, in order to get a number as lesser as rank as possible, we must sort 6 3 2 array i.e. 1 5 4 2 3 6 
 *  As 6 3 2 will always be Desc order, we just have to reverse it
 * 
 *  STEPS -> 
 *   Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
 *   Find the largest index l > k such that nums[k] < nums[l].
 *   Swap nums[k] and nums[l].
 *   Reverse the sub-array nums[k + 1:].
 * 
 *  BONUS -> There's a library function in Cpp to solve this
 *  
 *  void nextPermutation(vector<int>& nums) {
        next_permutation(begin(nums), end(nums));
    } 
 */

    void nextPermutation(vector<int>& nums) {
        int i,j,n=nums.size();
        for(i=n-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) 
                break;
        }
        
        if(i<0)
            reverse(nums.begin(),nums.end());
        else {
            for(j=n-1;j>=i;j--)
                if(nums[j] > nums[i])
                    break;
            swap(nums[i] , nums[j]);
            reverse(nums.begin()+i+1 , nums.end());
        }
    }