1-> Reverse the string

    Question Link -> https://leetcode.com/problems/reverse-string/

    void reverseString(vector<char>& s) {
            
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            swap(s[i++],s[j--]);
        }
    }
