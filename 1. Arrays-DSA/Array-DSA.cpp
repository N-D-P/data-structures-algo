Array - DSA

1-> Reverse the string

    Question Link -> https://leetcode.com/problems/reverse-string/

    void reverseString(vector<char>& s) {
            
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            swap(s[i++],s[j--]);
        }
    }

2-> Maximum and minimum of an array

    vector<int> getMinMax(vector<int>&arr , int n)
    {
        vector<int> result(2); //result array, 0-> max | 1->min
        int i; //index

        // If array has even number of elements 
        // then initialize the first two elements 
        // as minimum and maximum
        if(n%2 == 0)
        {
            if(arr[0] > arr[1])
            {
                result[0] = arr[0];
                result[1] = arr[1];
            }
            else
            {
                result[0] = arr[1];
                result[1] = arr[0];
            }
            //set starting index for loop
            i = 2;
        }
        // If array has odd number of elements 
        // then initialize the first element as 
        // minimum and maximum
        else
        {
            result[0] = result[1] = arr[0];
            //set starting index for loop
            i = 1;
        }
        while(i < n-1)
        {
            if(arr[i] > arr[i+1])
            {
               result[0] = max(arr[i],result[0]);
               result[1] = min(arr[i+1],result[1]);
            }
            else
            {
                result[0] = max(arr[i+1],result[0]);
                result[1] = min(arr[i],result[1]);
            }
            //Increment the index by 2 as
            //two elements are processed in loop
            i += 2;
        }
        return result;
    }

3-> Kth Largest element in an array

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

5-> Move all the negative elements to one side of the array 
    void shiftall(int arr[], int left, int right)
    {
    // Loop to iterate over the 
    // array from left to the right
        while (left<=right)
        {
            // Condition to check if the left
            // and the right elements are 
            // negative
            if (arr[left] < 0 && arr[right] < 0)
            left+=1;
            
            // Condition to check if the left 
            // pointer element is positive and 
            // the right pointer element is negative
            else if (arr[left]>0 && arr[right]<0)
            {
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left+=1;
            right-=1;
            }
            
            // Condition to check if both the 
            // elements are positive
            else if (arr[left]>0 && arr[right] >0)
            right-=1;
            else{
            left += 1;
            right -= 1;
            }
        }
    }

6-> Find Union 
    int doUnion(int a[], int n, int b[], int m)  {
        map<int,int> freq;
        for(int i=0;i<n;i++)
            freq[a[i]]++;
        for(int j=0;j<m;j++)
            freq[b[j]]++;
        return freq.size();
    }


7-> Clockwise rotation
    void rotate(int arr[] , int n)
    {
        int last = arr[n-1];
        for(int i=n-1;i>=1;i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = last;
    }

8-> Kandane's Algorithm
    
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

9-> Shortest Unsorted Continuous Subarray

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

10-> Valid stack sequence

    Given two integer arrays pushed and popped each with distinct values, 
    return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

    Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    Output: true
    Explanation: We might do the following sequence:
    push(1), push(2), push(3), push(4),
    pop() -> 4,
    push(5),
    pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

 bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int i = 0;
        for (int x : pushed) {
            stack.push(x);
            while (stack.size() && stack.top() == popped[i]) {
                stack.pop();
                i++;
            }
        }
        return stack.size() == 0;
    }

11-> Rotate Array 

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


12->  Minimise the maximum difference between heights 

    Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or 
    decreasing them by K only once. After modifying, height should be a non-negative integer. 
    Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower

    Example 1:
    Input:
    K = 2, N = 4
    Arr[] = {1, 5, 8, 10}
    Output:
    5
    Explanation:
    The array can be modified as 
    {3, 3, 6, 8}. The difference between 
    the largest and the smallest is 8-3 = 5.

    int getMinDiff(int arr[], int n, int k) {

       vector<int> array;
       sort(arr,arr+n);
       
       int answer = arr[n-1]-arr[0];     
       int smallest = arr[0]+k;
       int largest = arr[n-1]-k;
       int minn=0,maxx=0;
       
       for(int i=0;i<n-1;i++)
       {
            minn = min(smallest , arr[i+1]-k);
            maxx = max(largest , arr[i]+k); //we choose immediate pair becase that is the minimum diff we can get for current pair insorted array
            if(minn < 0) continue;
            answer = min(answer , maxx-minn);
       }
      return answer;
    }

13->

13.1-> Jump Game I  https://leetcode.com/problems/jump-game/

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

14-> Duplicate numbers 

video ref-> https://www.youtube.com/watch?v=9YTjXqqJEFE 
Question Link-> https://leetcode.com/problems/find-the-duplicate-number/

floyd cycle detection method

    int findDuplicate(vector<int>& nums) {
        //Floyd's Tortoise and Hare (Cycle Detection)
        int slow=nums[0],fast=nums[0];
        
        do //phase 1
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

15-> Largest Rectangle in Histogram

    Video Ref-> https://www.youtube.com/watch?v=ZmnqCZp9bBs
    Question Link-> https://leetcode.com/problems/largest-rectangle-in-histogram/

    1. Add to stack if current value is greater then or equal to the top of the stack
    2. Otherwise keep removing from stack till a number whaich is smaller than or equal then current is found
    3. Calculate area everytime you remove from stack
        if(stack.isEmpty())
            area = input[top] * i;
        else
            area = input[top] * (i-top-1);

    int largestRectangleArea(vector<int>& heights) {
              
        stack<int> stack;
        int area=0,maxarea=0,top=0,i;
        
        for( i=0;i<heights.size();)
        {
            if(stack.empty() || heights[i]>=heights[stack.top()])
            {
                stack.push(i);
                i++;
            }
            else
            {
                top = stack.top();
                stack.pop();
                if(stack.empty())
                {
                    area = heights[top] * i;    
                }
                else
                {
                    area = heights[top] * (i-stack.top()-1);
                }
                
                maxarea = area>maxarea?area:maxarea;
            }
        }
        
        while(!stack.empty())
        {
            top = stack.top();
            stack.pop();
            if(stack.empty())
            {
                area = heights[top] * i;
            }
            else
            {
                area = heights[top] * (i-stack.top()-1);
            }
            maxarea = area>maxarea?area:maxarea;
        }
        
        return maxarea;
    }

16-> Array Nesting

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

17-> Erect The Fence
    video Link -> https://www.youtube.com/watch?v=Vu84lmMzP2o
    Question Link-> https://leetcode.com/problems/erect-the-fence/

    /*
        Convex hull or convex envelope of a set X of points in the Euclidean plane or in a Euclidean space
    * (or, more generally, in an affine space over the reals) is the smallest convex set that contains X.
    *
    * Jarvis March is finding convex or gift wrapping algorithm.
    *
    * Time complexity O(nh)
    *    n - number of points
    *    h - number of points on the boundary.
    *    Worst case O(n^2)
    *
    * Space complexity O(n^2)
    */

    public class JarvisMarchConvexHull {

    class Point{
        int x;
        int y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public List<Point> findConvexHull(Point[] points) {
        //first find leftmost point to start the march.
        Point start = points[0];
        for (int i = 1; i < points.length; i++) {
            if (points[i].x < start.x) {
                start = points[i];
            }
        }
        Point current = start;
        //use set because this algorithm might try to insert duplicate point.
        Set<Point> result = new HashSet<>();
        result.add(start);
        List<Point> collinearPoints = new ArrayList<>();
        while (true) {
            Point nextTarget = points[0];
            for (int i = 1; i < points.length; i++) {
                if (points[i] == current) {
                    continue;
                }
                int val = crossProduct(current, nextTarget, points[i]);
                //if val > 0 it means points[i] is on left of current -> nextTarget. Make him the nextTarget.
                if (val > 0) {
                    nextTarget = points[i];
                    //reset collinear points because we now have a new nextTarget.
                    collinearPoints = new ArrayList<>();
                } else if (val == 0) { //if val is 0 then collinear current, nextTarget and points[i] are collinear.
                    //if its collinear point then pick the further one but add closer one to list of collinear points.
                    if (distance(current, nextTarget, points[i]) < 0) {
                        collinearPoints.add(nextTarget);
                        nextTarget = points[i];
                    } else { //just add points[i] to collinearPoints list. If nextTarget indeed is the next point on
                        //convex then all points in collinear points will be also on boundary.
                        collinearPoints.add(points[i]);
                    }
                }
                //else if val < 0 then nothing to do since points[i] is on right side of current -> nextTarget.
            }

            //add all points in collinearPoints to result.
            for (Point p : collinearPoints) {
                result.add(p);
            }
            //if nextTarget is same as start it means we have formed an envelope and its done.
            if (nextTarget == start) {
                break;
            }
            //add nextTarget to result and set current to nextTarget.
            result.add(nextTarget);
            current = nextTarget;
        }
        return new ArrayList<>(result);
    }

    /**
     * Returns < 0 if 'b' is closer to 'a' compared to 'c', == 0 if 'b' and 'c' are same distance from 'a'
     * or > 0 if 'c' is closer to 'a' compared to 'b'.
     */
    private int distance(Point a, Point b, Point c) {
        int y1 = a.y - b.y;
        int y2 = a.y - c.y;
        int x1 = a.x - b.x;
        int x2 = a.x - c.x;
        return Integer.compare(y1 * y1 + x1 * x1, y2 * y2 + x2 * x2);
    }

    /**
     * Cross product to find where c belongs in reference to vector ab.
     * If result > 0 it means 'c' is on left of ab
     *    result == 0 it means 'a','b' and 'c' are collinear
     *    result < 0  it means 'c' is on right of ab
     */
    private int crossProduct(Point a, Point b, Point c) {
        int y1 = a.y - b.y;
        int y2 = a.y - c.y;
        int x1 = a.x - b.x;
        int x2 = a.x - c.x;
        return y2 * x1 - y1 * x2;
    }
    }