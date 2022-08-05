video ref-> https://www.youtube.com/watch?v=9YTjXqqJEFE 
Question Link-> https://leetcode.com/problems/find-the-duplicate-number/

1. Naive approach 
    - Take a map<int,bool>
    - Loop through array, mark map[nums[i]] = !map[nums[i]]
    - if(map[nums[i]] is equal to FALSE)
        that means it is a number that has been encountered previously.
    - return that number.
2. floyd cycle detection method

    int findDuplicate(vector<int>& nums) {
        //Floyd's Tortoise and Hare (Cycle Detection)
        int slow=nums[0],fast=nums[0];
        
        do //phase 1hhh
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        slow = nums[0];
        
        while(slow!=fast) //phase 2
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return fast;
    }
