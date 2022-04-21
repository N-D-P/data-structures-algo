    Question Link - https://leetcode.com/problems/maximum-subarray/;
    
    int maxSubArray(vector<int>& nums) {
        int max_local=nums[0] , max_global=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            max_local = max(nums[i] , nums[i]+max_local);
            max_global = max(max_global , max_local);
        }
        return max_global;
    }
