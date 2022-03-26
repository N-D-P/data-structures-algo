Searching_sorting-DSA

1-> Find the first and last position of an element in a sorted array 
    Question Link -> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

    lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 
    upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 

    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = lower_bound(nums.begin() , nums.end() , target) - nums.begin();
        if(lo == nums.size() || nums[lo] != target) 
            return {-1,-1};
        int hi = upper_bound(nums.begin() , nums.end() , target) - nums.begin() - 1;
        
        return {lo,hi}; 
    }
     Alternate code with two binary searches

      public int[] searchRange(int[] nums, int target) {
        
        int[] result = new int[2];
        result[0] = findFirst(nums,target);
        result[1] = findLast(nums,target);
        return result;
        
    }
    
    public int findFirst(int[] nums, int target){
        
        int result = -1;
        int low = 0;
        int high = nums.length - 1;

        while(low <= high){
            int mid = low + ((high-low)/2);

            if (nums[mid] < target){
                low = mid +1;
            } else if (nums[mid] > target){
                high = mid - 1;
            } else { // nums[mid] == target
                result = mid;

                // because nothing after mid
                // can be the first occurance of target.
                //maybe mid is the first occurance , maybe not
                //so let's narrow the target for [0...mid-1] and find out
                high = mid - 1; 
   
            }
        }

        return result;
  
    }
    
        public int findLast(int[] nums, int target){
        
        int result = -1;
        int low = 0;
        int high = nums.length - 1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if (nums[mid] < target){
                low = mid +1;
            } else if (nums[mid] > target){
                high = mid - 1;
            } else { // nums[mid] == target
                result = mid;
                // because nothing before mid
                // can be the last occurance of target.
                //maybe mid is the last occurance , maybe not
                //so let's narrow the target for [mid+1...high] and find                   // out
                low = mid + 1;
   
            }
        }

        return result;
    }
 
2->  Find Pivot Index

    Qustion Link -> https://leetcode.com/problems/find-pivot-index/

        int pivotIndex(vector<int>& nums) {
        int totsum = 0;
        for(int x:nums) totsum+=x;
        
        int left = 0;
        int right = totsum;
        
        for(int i=0;i<nums.size();i++)
        {
            right -= nums[i];
            if(left == right) return i;
            left += nums[i];   
        }
        return -1;
    }

3-> Search in sorted array

    Question Link -> https://leetcode.com/problems/search-in-rotated-sorted-array/
    Video Ref -> https://www.youtube.com/watch?v=oTfPJKGEHcc&t=733s

    1. If we divide array into two equal parts, then there will be always atleast one strictly increasing part.
    2. To find out which part is it, we have to compare mid with left most element i.e [7,8,0,1,2,3,4,5,6] compare 2 with 7, 2 is small then 7 so right part will be strictly increasing
    3. Now, inside that increasing part find if the target is between that range,
    4. If yes then search in that range or else search in other part

        int search(vector<int>& nums, int target) {
        int mid = 0;
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right)
        {
            mid = (left+right)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[left] <= nums[mid])  //strictly increasing on left side
            {
                if(target >= nums[left] && target <= nums[mid]) //check if target is in left incresing side
                    right = mid-1;
                else
                    left = mid+1;
            }
            else //strictly incresing on right side
            {
                if(target >= nums[mid] && target <= nums[right]) //check if target is in right incresing side
                    left = mid +1;
                else
                    right = mid-1;
            }
        }
        
        return -1;
    }

4-> 