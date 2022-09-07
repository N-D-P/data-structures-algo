Video -> https://www.youtube.com/watch?v=lO9R5CaGRPY&list=PLByG0Le9gW1ukPzWdArXFN8iHh5OgUWOV

Question -> 
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples: 

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 5 are {5}
              and {5, 6, 7, 8, 9}

Approach 1 -> brute force,
Using nested loop we can traverse all the subarrays and keep a count of subarrays with xor as k 

Appraoch 2 -> Watch video for proper logic

int solve(vector<int> arr, int K) {
    map<int,int> freq;
    int xor = 0;
    int cnt = 0;
    for(auto ele : arr) {
        xor = xor ^ ele;

        if(xorr == K) 
            cnt++;

        if(freq.find(xor ^ K) != freq.end())
            cnt += freq[xorr ^ K];
        
        freq[xorr]++;
    }
    return cnt;
}

