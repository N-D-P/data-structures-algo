Binary_tree-DSA

1-> Level order travesring

   vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> level;
            int n = que.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* t = que.front(); que.pop();
                level.push_back(t->val);
                if(t->left)
                    que.push(t->left);
                if(t->right)
                    que.push(t->right);
            }
            res.push_back(level);
        }
        return res;

3-> Maximum depth of a binary tree
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int leftmax = maxDepth(root->left);
        int rightmax = maxDepth(root->right);
        return 1+max(leftmax,rightmax);
    }

4-> Diameter of a tree 

    1. Time Complexity -> O(n * height)

    int diameter(struct node* tree)
    {
        // base case where tree is empty
        if (tree == NULL)
            return 0;
    
        // get the height of left and right sub-trees
        int lheight = height(tree->left);
        int rheight = height(tree->right);
    
        // get the diameter of left and right sub-trees
        int ldiameter = diameter(tree->left);
        int rdiameter = diameter(tree->right);
    
        // Return max of following three
        // 1) Diameter of left subtree
        // 2) Diameter of right subtree
        // 3) Height of left subtree + height of right subtree + 1
        return max(lheight + rheight + 1,
                max(ldiameter, rdiameter));
    }
    
    /*The question can be solved by small modification to program of Height of tree.
    The idea is quite simple. Max value of Height(leftSubtree)+Height(rightSubtree) (at any node ) is the diameter. 
    Keep track of maxium diameter duing traversal and find the height of the tree.

    d=max(d,ld+rd); => This line maintains the max diameter.
    Time Complexity -> O(n)
    */
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        dfs(root,d);
        return d;
    }
    int dfs(TreeNode* root,int&d)
    {
        if(root == nullptr)
            return 0;
        int left = dfs(root->left,d);
        int right = dfs(root->right,d);
        d = max(d,left+right);
        return 1+max(left,right);
    }
    
5-> Create a mirror tree from the given binary tree

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        
        if(nullptr == root) return root;
        
        queue<TreeNode*> myQueue;   // our queue to do BFS
        myQueue.push(root);         // push very first item - root

        while(!myQueue.empty()){    // run until there are nodes in the queue 
            
            TreeNode *node = myQueue.front();  // get element from queue
            myQueue.pop();                     // remove element from queue
                    
            if(node->left != nullptr){         // add left kid to the queue if it exists
                myQueue.push(node->left);
            }
            
            if(node->right != nullptr){        // add right kid 
                myQueue.push(node->right);
            }
            
            // invert left and right pointers      
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;

        }

        return root;
    }

6-> Binary tree inorder traversal
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        while(true)
        {
            if(root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            else 
            {
                if(stk.empty()) break;
                res.push_back(stk.top()->val);
                root = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }

7-> binary tree preorder traversal
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return vector<int>();
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *curr = stk.top();
            res.push_back(curr->val);
            stk.pop();
            if(curr->right)
                stk.push(curr->right);
            if(curr->left)
                stk.push(curr->left);
        }
        return res;
    }

8-> Binary tree postorder traversal
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return vector<int>();
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *last = NULL;
        while(!stk.empty() || root !=nullptr)
        {
            if(root)
            {
                stk.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *node = stk.top();
                if(node->right && last!=node->right) //check if curr has right or not, and also is 'last' is not right child of curr
                    root = node->right;
                else
                {
                    res.push_back(node->val);
                    last = node;    //to store last popped element 
                    stk.pop();
                }
            }
        }
        return res;
    }

9-> Binary tree right side view 
10-> Binaty tree left side view 
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return vector<int>(); 
        vector<int> RightSide;
        vector<int> LeftSide;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *curr = q.front(); q.pop();
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            Leftside.push_back(level[0]); 
            RightSide.push_back(level[level.size()-1]);
        }
        return LeftSide or return RightSide;
    }



