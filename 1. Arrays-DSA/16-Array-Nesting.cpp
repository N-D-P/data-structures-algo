    You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

    You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

    The first element in s[k] starts with the selection of the element nums[k] of index = k.
    The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
    We stop adding right before a duplicate element occurs in s[k].
    Return the longest length of a set s[k].



    Example 1:

    Input: nums = [5,4,0,3,1,6,2]
    Output: 4
    Explanation: 
    nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
    One of the longest sets s[k]:
    s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}

    1. Take a Boolean 'Visted' array, to store the visited numbers
    2. Loop through input
    3. store current element in start variable,
    3. check if the element is prev visted or not, if not then
    4. using do while loop with terminating Condition as (nums[i] != start)
    5. In do while loop, 
        start = nums[start] //advance to next element
        temp++;     //a temp counter
        visted[start] = true; //mark the current element as visted  
        
    code->
        int arrayNesting(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        int start,temp,ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            start = nums[i],temp=0;
            if(vis[i] != true)
            {
                do{
                    start = nums[start];
                    temp++;
                    vis[start] = true;
                }while(nums[i] != start);
                
                ans = max(temp,ans);
            }
        }
        
        return ans;
    }
