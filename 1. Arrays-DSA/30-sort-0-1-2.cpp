// Question Link -> https://leetcode.com/problems/sort-colors/
// Video Link -> https://www.youtube.com/watch?v=oaVa-9wmpns

1-> Sort the array

2-> Counting sort 
    - Map the number of 0s 1s and 2s 
    - using loop fill the array with 0 1 2

3-> Dutch National Flag Algorithm 
    - Take three pointers, start , end , index
    - start will point zeroes, end will point twos, index for traversing.
    - traverse till index crosses high
    - when we encounter 0  in index swap nums[start] and nums[index] and increment start and index.
    - When we encounter 2 swap nums[end], nums[index], just decrement end 
      *dont Increment index, as we dont know what is at nums[end], it could be zero,one or two*

