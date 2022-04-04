/**
 * Question Link -> https://leetcode.com/problems/swapping-nodes-in-a-linked-list
 * 
 * Explanation -> 
 * 1.  We traverse the list until we reach the kth node.
        Then we set "kth" to that node to remember it, set ptr2 to head and continue traversing the list, while we move both ptr1 and ptr2.
        When ptr1 reaches the end - ptr2 is on the (n-k)th node.
        Now we swap "kth" and "ptr2" and we're done!

    2. Convert to array and swap element and again 
 * 
*/

    ListNode* swapNodes(ListNode* head, int k) {
        	ListNode *kthNode, *kthNodeFromEnd = head, *iter = head;
	while(--k)
		iter = iter -> next;
	kthNode = iter;
	while(iter -> next)
		iter = iter -> next, kthNodeFromEnd = kthNodeFromEnd -> next;
	swap(kthNode -> val, kthNodeFromEnd -> val);
	return head;
    }

    ListNode* swapNodes(ListNode* head, int k) {
    ListNode* dummy = head;
    ListNode* result = head;
    int size = 1;
    vector<int> arr;
    while(dummy != nullptr) {
        arr.push_back(dummy->val);
        dummy = dummy->next;
        size++;
    }
    int k1 = size - k;
    swap(arr[k-1] , arr[k1-1]);
    int j=0;
    while(result) {
        result->val = arr[j];
        j++;
        result = result->next;
    }
    return head;
    