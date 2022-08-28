Question Link -> https://leetcode.com/problems/majority-element-ii/
Video -> striver 

Question -> Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times

Approach 1 -> Brute Force

Take i and j, traverse all the right elements of i using j, and check if frequency is greater then n/3

Approach 2 -> Store in map,

Store the freq of elements in map

Approach 2 -> Optimal Moore voting algo 

It is guarantee that there will be maximum of 2 answer

e1 and e2 for storing maximum elements. 
c1 and c2 for count of e1 and e2.

Same as prev prob, if c1 is 0, assign nums[i] to e1 and if c2 is zero assign nums[i] to e2
if e1 == nums[i], c1++ -- else if(e2 == nums[i]) c2++, else c1-- c2--

Drawback is we cant guarantee that e1 and e2 have frequency greater then n/3, so we have to 
loop again to look at the greq of e1 and e2 to make sure it is greater then n/3 


        //Moore's voting algorithm
        int e1=0, e2=0, c1=0, c2=0;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == e1) {
                c1++;
            }
            else if(nums[i] == e2) {
                c2++;
            }
            else if(c1 == 0) {
                e1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0) {
                e2 = nums[i];
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }
        
        c1 = c2 = 0;
        
        for(int num : nums) {
            if(num == e1)
                c1++;
            else if(num == e2)
                c2++;
        }

        if(c1 > nums.size()/3) res.push_back(e1);
        if(c2 > nums.size()/3) res.push_back(e2);
        
        return res;
    }

