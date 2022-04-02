/*
 * Question Link -> https://leetcode.com/problems/valid-palindrome-ii/
*/


class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i < j) {
            if(s[i] == s[j]) {
                i++; j--;
            }
            else {
                return checkPalim(s,i,j-1) || checkPalim(s,i+1,j);
            }
        }
        return true;
    }
    
    bool checkPalim(string s,int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};