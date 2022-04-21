    Given an array, rotate the array to the right by k steps, where k is non-negative.
    https://leetcode.com/problems/rotate-array/

  void rotate(vector<int>& nums, int k) {
        if(k==0) return;
        k=k%nums.size();
        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k , nums.end());
        
    }

    /*
    i/p-> 1 2 3 4 5 6 7 8 , k = 3
    Reverse the whole array 8 7 6 5 4 3 2 1
    Reverse the first k terms 6 7 8 4 3 2 1
    Reverse the last k terms  6 7 8 1 2 3 4
    NOTE-> K can be larger than the Size, so perform modular, i.e k%size(),
    ex, size=8 and k=10 this will perform only 2 rotation therefore modular
    */
