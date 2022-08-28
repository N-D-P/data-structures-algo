Question -> https://leetcode.com/problems/4sum/
Video -> striver 

question -> Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Approach 1 -> Brute force


Approach 2 -> Optimal 


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //sort the array for binary search
    sort(nums.begin(), nums.end());

    int n = nums.szie();
    vector<vector<int>> res;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int target_2 = target - nums[i] - nums[j];
            // For binary search from j+1 to n-1
            int left = j+1;
            int right = n-1;
            while (left < right)
            {
                if(target_2 < (nums[left] + nums[right]))
                    left++;
                else if(target_2 > (nums[left] + nums[right]))
                    right--;
                else {
                    vector<int> quad(4,0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];
                    res.push_back(quad);
                    //To avoid similar elements on left and right
                    while(left < right and nums[left] == quad[2]) ++left;
                    while(left < right and nums[right] == quad[3]) --right;
                }
            }
            //to avoid duplicate nums[j]
            while(j+1<n and nums[j+1] == nums[j]) ++j;
        }
        // to avoid duplicates i
        while(i+1<n and nums[i+1] == nums[i]) ++i;
    }
    return res;
};