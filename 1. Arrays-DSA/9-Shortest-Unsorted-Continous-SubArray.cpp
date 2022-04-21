    Question Link -> https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

9.1-> TC-O(log N) SC-O(N);
    int findUnsortedSubarray(vector<int>& nums) {
      vector<int> arr(nums);
        sort(arr.begin() , arr.end());
        int start = 0, end = nums.size()-1;
        for(;start < nums.size(); start++) {
            if(nums[start] != arr[start]) break;
        }
        if(start >= nums.size()-1) return 0;
        for(; end>=0; end--){
            if(nums[end] != arr[end]) break;
        }
        
        return end-start+1;
    }

9.2->   
    public int findUnsortedSubarray(int[] nums) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        int n = nums.length;
        
        for(int i = 1; i < n; i++){
            //Decreasing Value
            if(nums[i] < nums[i-1]) {
                min = Math.min(min,nums[i]);
            }
        }
        
        for(int i = n-2; i >= 0; i--) {
            //Increasing value
            if(nums[i] > nums[i+1]){
                max = Math.max(max,nums[i]);
            }
        }
        if(min == Integer.MAX_VALUE && max == Integer.MIN_VALUE) return 0;
        
        int start = 0, end = n-1;
        
        for(; start < n; start++) {
            if(nums[start] > min) break;
        }
        
        for(; end >= 0; end--) {
            if(nums[end] < max) break;
        }
        
        return end-start+1;
    }
