3.1-> Sorting 
 int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin() , nums.rend());
        return nums[k-1];
 }

3.2-> Partial Sorting 
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }

3.3-> Max Heap 
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
3.4-> Min heap
3.5-> Partioning
