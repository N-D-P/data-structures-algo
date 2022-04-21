// https://leetcode.com/problems/recover-binary-search-tree/
//You are given the root of a binary search tree (BST), where the values of exactly 
//two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
// Referred Striver's video

TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    // Business
    if (prev)
    {
        if (root->val < prev->val)
        {
            if (!first)
            {
                first = prev;
            }
            second = root;
        }
    }

    prev = root;

    inorder(root->right);
}
void recoverTree(TreeNode *root)
{
    inorder(root);
    swap(first->val, second->val);
    return;
}

// Approx 2
vector<int> arr;
int index = 0;
void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    arr.push_back(root->val);
    inorder(root->right);
}
void inorder2(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder2(root->left);
    // Business
    if (root->val != arr[index])
        root->val = arr[index];
    index++;

    inorder2(root->right);
}
void recoverTree(TreeNode *root)
{
    inorder(root);
    sort(arr.begin(), arr.end());
    inorder2(root);
}