Question -> GFG
Video -> striver

Question Given an array arr[] of length N, find the length of the longest sub-array with a sum equal to 0.

Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
Output: 5
Explanation: The longest sub-array with elements summing up-to 0 is {-2, 2, -8, 1, 7}

Input: arr[] = {1, 2, 3}
Output: 0
Explanation: There is no subarray with 0 sum

Input:  arr[] = {1, 0, 3}
Output:  1
Explanation: The longest sub-array with elements summing up-to 0 is {0}

Appraoch 1 -> brute force

Using nested loops find all possible subarray and return the maximum length

Approach 2 -> Better

Basic idea is //Too hard to write it all, please watch the video for better clarity
Will try to comments in code as much I atomic_cancel

int solve(vector<int> nums) {
    
    int res = 0;
    map<int,int> freq;
    int S = 0;

    for(int i=0; i<nums.size(); i++) {
        S += nums[i];

        if(S == 0) 
            res = max(res, i+1);
        
        if(freq.find(S) != freq.end()) 
            res = max(res, i-freq[S]);
        else 
            freq[S] = i;
    }

    return res;

}

