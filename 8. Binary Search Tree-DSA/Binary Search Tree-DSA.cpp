Binary Search Tree-DSA

1-> Unique Binary Search Tree 2
    vector<TreeNode*> generateTrees(int n) {
       return generateTrees(1,n);
    }
    
    vector<TreeNode*> generateTrees(int start , int end)
    {
        vector<TreeNode*> res;
        if(start > end)  res.push_back(0);
        if(start == end)  res.push_back(new TreeNode(start));
        if(start < end)
        {
            for(int i=start ; i<=end ; i++)
            {
                vector<TreeNode*> l = generateTrees(start , i-1);
                vector<TreeNode*> r = generateTrees(i+1 , end);
                
                for(int j=0;j<l.size();j++)
                {
                    for(int k=0;k<r.size();k++)
                    {
                        TreeNode *curr = new TreeNode(i);
                        curr->left = l[j];
                        curr->right = r[k];
                        res.push_back(curr);
                    }
                }
            }
        }
        return res;
    }

2-> Search in BST

    TreeNode* searchBST(TreeNode* root, int val) {
        // Base Cases: root is null or key is present at root
        if(root == nullptr or root->val == val)
            return root;
         // Key is greater than root's key
        else if(root->val < val)
            return searchBST(root->right , val);
         // Key is smaller than root's key
        else
            return searchBST(root->left , val);
    }

3-> Delete in BST

    Video_link -> https://www.youtube.com/watch?v=kouxiP_H5WE

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == nullptr) return root;
        
        if(root->val == key) return helper(root);
        
        TreeNode *dummy = root;
        
        while(root != nullptr)
        {
            if(root->val > key)
            {
                if(root->left!=nullptr and root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if(root->right!=nullptr and root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        
        return dummy;
    }
    
    TreeNode* helper(TreeNode* root)
    {
        if(root->right == nullptr) return root->left;
        else if(root->left == nullptr) return root->right;
        
        TreeNode *rightChild = root->right;
        TreeNode *lastRightChild = lastRightchild(root->left);
        
        lastRightChild->right = rightChild;
        
        return root->left;
    }
    
    TreeNode* lastRightchild(TreeNode* root)
    {
        if(root->right == nullptr)
            return root;
        return lastRightchild(root->right);
    }

4-> Find min/max in BST 

    int minValue(Node* root) {
    // Code here
     if(root->left == nullptr) return root->data;
        
        while(root->left != nullptr)
        {
            root = root->left;
        }
        return root->data;
    }

5-> Inorder predecessor and successor for a given key in BST

    1. In order to find predecessor in Inorder, we have to find the imediate smaller element then key, in order to do that, we goto once left then extreme right, by this we can get 
        most immediate predecessor, same procdedure for successor, go once right, then extreme left.
    2. By above method we cannot find predecessor and successor for leaf node, to solve this we have to update predecessor and successor every time we move left and right,
    3. If we move left(root->key > key) then successor = root, then recursively call findPreSuc(root->left, pre, suc, key) 
    4. If we move right(root->key < key) then predecessor = root, then recursively call findPreSuc(root->right,pre,suc,key)

    // It sets pre and suc as predecessor and successor respectively
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Base case
        if (root == NULL)  return ;
    
        // If key is present at root
        if (root->key == key)
        {
            // the maximum value in left subtree is predecessor
            if (root->left != NULL)
            {
                Node* tmp = root->left;
                while (tmp->right)
                    tmp = tmp->right;
                pre = tmp ;
            }
    
            // the minimum value in right subtree is successor
            if (root->right != NULL)
            {
                Node* tmp = root->right ;
                while (tmp->left)
                    tmp = tmp->left ;
                suc = tmp ;
            }
            return ;
        }
    
        // If key is smaller than root's key, go to left subtree
        if (root->key > key)
        {
            suc = root ;
            findPreSuc(root->left, pre, suc, key) ;
        }
        else // go to right subtree
        {
            pre = root ;
            findPreSuc(root->right, pre, suc, key) ;
        }
    }

6-> Validate if the given tree is BST or not
 Video_link : https://www.youtube.com/watch?v=MILxfAbIhrE
 question_link : https://leetcode.com/problems/validate-binary-search-tree/

 6.1-> Recursive

    Keep min, max for every recursion. Initial min and max is very small and very larger
    number. Check if root.data is in this range. When you go left pass min and root.data and 
    for right pass root.data and max.
    Note we use LONG_MIN and LONG_MAX to handle edge cases like [INT_MAX].

        bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    
    bool isValidBST(TreeNode*root,long minn,long maxx)
    {
        if(root == nullptr) return true;
        
        if(root->val <= minn or root->val >= maxx) return false;
        
        bool leftCheck = isValidBST(root->left,minn,root->val);
        
        bool rightCheck = isValidBST(root->right,root->val,maxx);
        
        return leftCheck and rightCheck;
    }

 6.2-> Iterative 

 The iterative idea is to apply iterative inorder traversal to the tree and check whether the current value is always larger than the previous one.

     bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        stack<TreeNode*> stk;
        long prev = LONG_MIN;
        
        while(true)
        {
            if(root != nullptr)
            {
                stk.push(root);
                root=root->left;
                
            }
            else
            {
                if(stk.empty()) break;
                if(prev >= stk.top()->val) return false; //compare previous node value to current node value in INORDER
                //cout<<stk.top()->val<<" ";
                prev=stk.top()->val; //store current node as prev node before pop()
                root=stk.top()->right;
                stk.pop();
            }
        }
        
        return true;
    }


