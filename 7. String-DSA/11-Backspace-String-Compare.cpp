Given two strings s and t, return true if they are equal when both are typed into empty text editors.'#' means a backspace character.

    Note that after backspacing an empty text,
    the text will continue empty.

    Example 1 :

    Input : s = "ab#c",
            t = "ad#c" Output : true Explanation : Both s and t become "ac".
    https:// leetcode.com/problems/backspace-string-compare/
    // Solution 1
    // Using Stacks
    /**
     * take 2 stacks, s1 and s2
     * loop through every char in both string
     * if( char is equal to # AND stack is not empty)
     *      pop from stack;   // # acts as a backspace in string
     * else if( char not equal to #)
     *      push char to stack
     * compare both stacks
     * return true if both equal or false.
    */
    bool backspaceCompare(string S, string T)
    {
        stack<char> s1, s2; // s1--->S     s2--->T
        char x, y;

        for (int i = 0; i < S.length(); i++)
        {
            x = S[i];
            if (x == '#' and !s1.empty())
            {
                s1.pop();
            }
            else if (x != '#')
                s1.push(x);
        }

        for (int i = 0; i < T.length(); i++)
        {
            y = T[i];
            if (y == '#' and !s2.empty())
            {
                s2.pop();
            }
            else if (y != '#')
                s2.push(y);
        }
        return s1 == s2;
    }

// Solution 2
/**
 * Implementation using two pointer- 1st to traverse the string and second to store the character at given position

Suppose 2 pointer i & k
Start traversing the by first pointer(i) if it is # then decrease the 2nd pointer(k )(k>=0) .And if it is not # then increase the pointer(k) and store the element at k th position.
S[k]=S[i]
Same will be done to 2nd string And suppose its 2nd pointer is p
If k and p are not equal means the string have differnt length. If same, then compare every element.
*/

bool backspaceCompare(string s, string t)
{
    int k = 0, p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            k--;
            k = max(0, k);
        }

        else
        {
            s[k] = s[i];
            k++;
        }
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '#')
        {
            p--;
            p = max(0, p);
        }

        else
        {
            t[p] = t[i];
            p++;
        }
    }
    if (k != p)
        return false;
    else
    {
        for (int i = 0; i < k; i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
}