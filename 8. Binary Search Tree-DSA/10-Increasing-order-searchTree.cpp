//Question Link -> https://leetcode.com/problems/increasing-order-search-tree/
/*
Given the root of a binary search tree, 
rearrange the tree in in-order so that the leftmost node in the 
tree is now the root of the tree, 
and every node has no left child and only one right child.
*/

vector<int> arr;
TreeNode *increasingBST(TreeNode *root)
{
    inorder(root);
    TreeNode *temp;

    TreeNode *res = new TreeNode(0);
    temp = res;

    for (int x : arr)
    {
        cout << x << " ";
        temp->right = new TreeNode(x);
        temp = temp->right;
    }
    return res->right;
}

void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    arr.push_back(root->val);
    inorder(root->right);
}