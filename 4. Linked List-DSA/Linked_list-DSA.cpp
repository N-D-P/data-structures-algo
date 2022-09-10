Linked_list-DSA

1 ->  Reverse a List
2 ->  Detect a cycle in List 
3 ->  Return the staring point of Loop
4 ->  Remove Loop from List 
5 ->  Remove duplicates in sorted Linked list
6 ->  Remove duplicates in unsorted linked list
7 ->  Swap first and last element of linked list
8 ->  Add One to the Linked_list
9 ->  Add two Number represented by Linked_list
10->  Interaction point of 2 list

1->Reverse a Linked list
    //Iterative
        ListNode* reverseList(ListNode* head) {
            ListNode *curr=head,*prev = NULL,*next;
            while(curr!=NULL)
            {
                next = curr->next;  //save next 
                curr->next = prev;  //reverse
                prev = curr;  //advance prev
                curr = next; //advance curr
            }
            return prev;   //new head at the end
        }
    //recursive
        ListNode* reverseList(ListNode* head) {
            if(head == NULL or head->next == NULL) return head; 
            ListNode *newhead = reverseList(head->next); //down down down
            head->next->next = head; // reverse
            head->next = NULL; //reverse
            return newhead; //up 
        }

2-> Detect a cycle in Linked list 
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }

3-> Return the starting point of the loop 
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode*slow=head,*fast=head;
        bool iscycle = false;
        while(fast != NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if(!iscycle) return NULL;
        
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        /*
        while(fast->next != slow)
            fast = fast->next;
        fast->next = nullptr;
        */
    }

4-> Remove Loop from Linked list

        ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode*slow=head,*fast=head;
        bool iscycle = false;
        while(fast != NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if(!iscycle) return NULL;
        
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        while(fast->next != slow)
            fast = fast->next;
        fast->next = nullptr;
        
    }
    

5-> Remove duplicates in sorted Linked list 
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *first=head;
        while(first!=NULL && first->next!=NULL){
            if(first->val==first->next->val){
                first->next=first->next->next;
            }else{
                first=first->next;
            }
        }
        return head;
    }

6-> Remove duplicates in unsorted linked list 
    void removeDuplicates(struct Node *start)
    {
        // Hash to store seen values
        unordered_set<int> seen;
    
        /* Pick elements one by one */
        struct Node *curr = start;
        struct Node *prev = NULL;
        while (curr != NULL)
        {
            // If current value is seen before
            if (seen.find(curr->data) != seen.end())
            {
            prev->next = curr->next;
            delete (curr);
            }
            else
            {
            seen.insert(curr->data);
            prev = curr;
            }
            curr = prev->next;
        }
    }

7-> Swap first and last element of linked list 
    void moveToFront(Node **head_ref)  
    {  
        if (*head_ref == NULL || (*head_ref)->next == NULL)  
            return;  
        /* Initialize second last and last pointers */
        Node *secLast = NULL;  
        Node *last = *head_ref;  
        /*After this loop secLast contains address of second last node and  
        last contains address of last node in Linked List */
        while (last->next != NULL)  
        {  
            secLast = last;  
            last = last->next;  
        }  
        /* Set the next of second last as NULL */
        secLast->next = NULL;  
        /* Set next of last as head node */
        last->next = *head_ref;  
        /* Change the head pointer to point to last node now */
        *head_ref = last;  
    }  

8-> Add One to the Linked_list


    Node *addOne(Node *head)
    {
    head=rev(head);
    //cout<<head->data<<"\n\n";
    Node *ptr=head,*prev;
    int carry=1,sum=0;
    while(ptr!=NULL){
        //cout<<"ptr->data:"<<ptr->data<<"\n";
        sum=(ptr->data)+carry;
        carry=sum/10;
        if(sum>=10){
            sum=sum%10;
        }
        ptr->data=sum;
        //cout<<"ptr->data after addition:"<<ptr->data<<"\n";
        prev=ptr;
        ptr=ptr->next;
    }
    if(carry){
        Node *newNode=(Node*)malloc(sizeof(Node));
        newNode->data=carry;
        prev->next=newNode;
        newNode->next=NULL;
    }
    
    head=rev(head);
    //cout<<head->data<<"\n\n";
    return head;
    }

9-> Add two Number represnted by Linked_list

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        int sum = 0;
        ListNode *dummy = new ListNode();
        ListNode *head = dummy;
        while(l1 != nullptr || l2 != nullptr)
        {
            sum = 0;
            if(l1!=nullptr) sum += l1->val;
            if(l2!=nullptr) sum += l2->val;
            sum += carry;
            //sum = l1->data + l2->data + carry;
            carry = sum>=10?1:0;
            sum%=10;
           
            head->next =   new ListNode(sum);
            head = head->next;
            
            if(l1!=nullptr) l1 = l1->next;
            if(l2!=nullptr) l2 = l2->next;
        }
        
        if(carry > 0)
        {
            head->next = new ListNode(carry);
            head = head->next;// = nullptr;
        }
        
        return dummy->next;
        
    }

10-> Interaction of two points

    ListNode * getIntersectionNode ( ListNode * headA , ListNode * headB ) {
        if ( headA == NULL 11 headB == NULL ) return NULL ;

        ListNode * a = headA ;
        ListNode * b headB ;
        
        // ifa & b have different len , then we will stop the loop after second iteration
        while a = b ) {
        }
            // for the end of first iteration , we just reset the pointer to the head of another linkedlist
            a = a == NULL ? headB a- > next ;
            b = b == NULL ? headA b- > next ;
        }
        return a ;
    }

        
