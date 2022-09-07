https://leetcode.com/problems/majority-element/
https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLByG0Le9gW1ukPzWdArXFN8iHh5OgUWOV

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Approach 1 -> 
Use map to store the count of each element and return the element with count greater
then n/2

Approach 2 ->
Moore Voting Algorithm
consider i/p 2,2,1,3,1,2,2,2,1
2 2 1 3 || 1 2 || 2 2 1  

divided in 3 sections, in first section majority ele is 2, but it is compensated with 
1,3 which is minority element. In second section there are equal number of elements
Finally in third section the 2 dominates the Majority element.

int majorityElement(vector<int> nums) {
    int cnt=0, ele;

    for(int i=0, i<nums.size();  i++) {
        
        if(cnt == 0) {
            ele = nums[i];
            cnt++;
        }

        if(ele == nums[i]) {
            cnt++;
        }
        else {
            cnt--;
        }
    }

    return ele;
}