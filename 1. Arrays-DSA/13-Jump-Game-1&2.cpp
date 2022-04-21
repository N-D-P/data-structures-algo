13.1-> Jump Game I  https://leetcode.com/problems/jump-game/


    bool canJump(vector<int>& nums) {
        // 163/169 passed
        if(nums.size() == 1) return true;
        if(nums[0] == 0) return false;
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] + i >= nums.size()-1) return true;
            while (nums[nums[i] + i] == 0) {
                if(nums[i] == 1) return false;
                nums[i]--;
                if(nums[i] == 0) {
                    return false;
                }
            };
        }
        return true;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastGoodPos = n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(i+nums[i] >= lastGoodPos)
                lastGoodPos =  i;
        }
        return lastGoodPos == 0;
    }

13.2- Jump Game II video ref Tushar Roy

    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size());
        
        for(int i=1;i<nums.size();i++)
        {
            dp[i] = INT_MAX;
            for(int j=0;j<i;j++)
            {
                if(j+nums[j] >= i)
                {
                     dp[i] = min(dp[i] , dp[j]+1);
                     break;
                }   
            }
        }
        return dp[nums.size()-1];
        
    }
