Question Link -> https://leetcode.com/problems/longest-consecutive-sequence/
Video -> 

Question : Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Approach 1 -> brute force

Sort the array, and keep track of conseqtive elements, and the max Consequetive number

Approach 2 -> Better

Store all elements in a set, loop the i/p array or the set itself. 
While looping if we encounter a element 'ele' such that the doesnt exsits another
element in set which is (ele - 1), "that means if their exists a sequence of consecative 
elements than this number should be the minimum of that sequence." then nestedly loop 
till there's a (ele + 1) exits in the set and keep increseing counter and ele ,
 "this will give us the maximum number of consequtove elements".

int longestConsecutive(vector<int>& nums) {
    set<int> set(nums.begin(), nums.end()); //store in set
    int maxCnt = 0; // global maximum
    for(auto num : nums) {
        if(!set.count(num-1)) { // if there's no element one less then num
            int currNum = num; // so that loop is not disturbed, num++ is also allowed
            int locCnt = 1; //local maximum
            while(set.count(currNum+1)) { // while there's num + 1 in set
                locCnt++;
                currNum++;
            }
            maxCnt = max(maxCnt, locCnt);
        }
    }
    return maxCnt;   
}

