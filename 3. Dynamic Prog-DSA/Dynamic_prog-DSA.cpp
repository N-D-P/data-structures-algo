Dynamic_prog-DSA

1-> Unique Binary Search Tree

    video ref-> https://www.youtube.com/watch?v=YDf982Lb84o&t=421s
    question_link-> https://leetcode.com/problems/unique-binary-search-trees/
    Given a sequence 1…n, we pick a number i out of the sequence as the root, then the number of unique BST with the specified root F(i), 
    is the cartesian product of the number of BST for its left and right subtrees. For example, F(3, 7): the number of unique BST tree with number 3 as its root. 
    To construct an unique BST out of the entire sequence [1, 2, 3, 4, 5, 6, 7] with 3 as the root, which is to say, 
    we need to construct an unique BST out of its left subsequence [1, 2] and another BST out of the right subsequence [4, 5, 6, 7], 
    and then combine them together (i.e. cartesian product). The tricky part is that we could consider the number of unique BST out of sequence [1,2] as G(2), 
    and the number of of unique BST out of sequence [4, 5, 6, 7] as G(4). Therefore, F(3,7) = G(2) * G(4).
    i.e.
    F(i, n) = G(i-1) * G(n-i)	1 <= i <= n 
    
    Combining the above two formulas, we obtain the recursive formula for G(n). i.e.
    G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0) 

    int numTrees(int n) {
       int dp[n+1];
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=n;i++)  //F(i,j) where i->root j->number of elements
        {
            dp[i] = 0;
            for(int j=0;j<i;j++)
            {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        
        return dp[n];
    }

2-> Coin change problem
  int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt+1 , amt+1);
        dp[0] = 0;
        for(int i=1;i<=amt;i++)
        {
            for(int coin : coins)
            {
                if(coin<=i)
                {
                    dp[i] = min(dp[i-coin]+1 , dp[i]);
                }
            }
        }
        return dp[amt]==amt+1?-1:dp[amt];
    }
