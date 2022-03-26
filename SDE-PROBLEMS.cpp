//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 1, 09-Feb-21

1-> Sort an array of 0’s 1’s 2’s without using extra space or sorting algo

 void sortColors(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return;
        int start=0,end=nums.size()-1,index=0;
        
        while(index<=end)
        {
            if(nums[index] == 0)
            {
                swap(nums[start],nums[index]);
                index++;
                start++;
            }
            else if(nums[index] == 2)
            {
                swap(nums[index],nums[end]);
                end--;
            }
            else
            {
                index++;
            }
        }
    }

2-> Find Missing And Repeating

    int *findTwoElement(int *arr, int n) {
        // code here
        int *res;
        res = new int[2];
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[arr[i]] == 2)
            {
                res[0] = arr[i];
                mp[arr[i]]--;
                break;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(mp[i] == 0)
            {
                res[1] = i;
                break;
            }
        }
        
        return res;
    }

4-> Kandane's Algo 

int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int max_global=arr[0];
    int max_local=arr[0];
    for(int i=1;i<n;i++)
    {
        max_local=max(arr[i] , arr[i]+max_local);
        max_global=max(max_local,max_global);
    }
    return max_global;
    
}

5-> Merge overlapping subintervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> merged;
        sort(intervals.begin() , intervals.end());
        for(auto interval : intervals)
        {
            if(merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else
                merged.back()[1] = max(merged.back()[1],interval[1]);
        }
        return merged;
    }
6->Convert BST to greater Tree 

int x = 0;
    TreeNode* convertBST(TreeNode* root) {
        
        if(root == NULL) return NULL;
        convertBST(root->right);
        x+=root->val;
        root->val = x;
        convertBST(root->left);
        return root;
    }

 int findDuplicate(vector<int>& nums) {
      
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }       
        return fast;
    }
//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 2, 10-Feb-21

1->Set matrix zero
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0=false,col0=false;
        int r=matrix.size(),c=matrix[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0) row0 = true;
                    if(j==0) col0 = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        if(row0)
            for(int i=0;i<c;i++)
                matrix[0][i]=0;
        if(col0)
            for(int j=0;j<r;j++)
                matrix[j][0]=0;
    }

2->Pascal's triangle'

    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        if(n==0) return res;
        vector<int> temp;
        temp.push_back(1);
        res.push_back(temp);
        if(n==1) return res;
        temp.push_back(1);
        res.push_back(temp);
        if(n==2) return res;
        for(int i=2;i<n;i++)
        {
            vector<int>tmp;
            tmp.push_back(1);
            for(int j=0;j<i-1;j++)
            {
                int x;
                x = res[i-1][j] + res[i-1][j+1];
                tmp.push_back(x);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        
        return res;
    }

3-> Next permutation
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k,l;
        for( k=n-2;k>=0;k--)
        {
            if(nums[k] < nums[k+1])
                break;
        }
        if(k<0)
        {
            reverse(nums.begin() , nums.end());
        }
        else
        {
            for(l=n-1;l>k;l--)
            {
                if(nums[l]>nums[k])
                    break;
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1 , nums.end());
        }
    }

4-> Count Inversions in an array | (Using Merge Sort)

int mergesort(int arr[],int n)
{
    int temp[n];
    return _mergesort(arr,temp,0,n-1);
}
int _mergesort(int arr[],int temp[],int left,int right)
{
    int mid, invcnt=0;
    while(left<right)
    {
        mid = (left+right)/2;
        invcnt += _mergesort(arr,temp,left,mid);
        invcnt += _mergesort(arr,temp,mid+1,right);

        invcnt += merge(arr,temp,left,mid+1,right);
    }
    return invcnt;
}
int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k,invcnt=0;
    i=left;
    j=right;
    k=left;

    while(i<=mid-1 && j<=right)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            invcnt+=(mid-i);
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];

    while(j<=right)
        temp[k++]=arr[j++];

    for(i=left;i<=right;i++)
        arr[i]=temp[i];
    
    return invcnt;
}
int main()
{
    int arr[] = {1,2,3,5,6,7,9,11,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = mergesort(arr,n);
    cout<<ans<<endl;
    return 0;
}

6-> copy list with random pointer
/* Deep copies the linked list (along with random pointers) */
Node* Solution :: copyRandomList(Node* originalHead)
{
    // Handle the corner case
    if(!originalHead) return originalHead;
    
    // Create the head of the cloned linked list and store its reference permanently
    Node* clonedHead = new Node(originalHead->val, nullptr, nullptr);
    
    // Create iterators for both the linked lists
    Node* newHead = clonedHead;
    Node* oldHead = originalHead;
    
    // Create a map which facilitates going vertically down from the original to cloned node
    unordered_map<Node*, Node*> nodeJustBelow;
    
    /* Node to Node mapping is compulsory to deal with duplicates in the linked list */
    
    // Link the nodes vertically
    nodeJustBelow[oldHead] = newHead;
    
    // Check whether the next node exists or not
    while(oldHead->next)
    {
        // First, create the next node in the cloned list.
        newHead->next = new Node(oldHead->next->val, nullptr, nullptr);
        
        // After the node has been created, step on it by the new thread
        newHead = newHead->next;
        oldHead = oldHead->next;
        
        // After you've moved to the newly created node, connect it vertically
        nodeJustBelow[oldHead] = newHead;
    }
    
    /* The linked list has been cloned correctly (except the random pointers) */

    // Traverse both the lists together and fill the random pointers
    oldHead = originalHead;
    newHead = clonedHead;
    
    // As long as both the lists exist, correct the random pointers
    while(oldHead && newHead)
    {
        // Traverse the random pointer of the original list and go down vertically and connect it
        newHead->random = oldHead->random? nodeJustBelow[oldHead->random] : nullptr;
        
        // Move forward in both the lists
        oldHead = oldHead->next;
        newHead = newHead->next;
    }
    
    // Return the stored reference of the cloned list
    return clonedHead;
}

5-> Best time to but and sell stock
 int maxProfit(vector<int>& prices) {
        int MinPri=INT_MAX;
        int MaxPro=0;
        for(int i=0;i<prices.size();i++)
        {
                MinPri = min(MinPri,prices[i]);
                MaxPro = max(MaxPro,prices[i]-MinPri);
        }
        return MaxPro;
        
    }

7-> Rotate image
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin() , matrix.end());
        for(int i=0;i<matrix.size();i++)
            for(int j=i;j<matrix.size();j++)
            {
                    swap(matrix[i][j] , matrix[j][i]);
            }
    }

//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 3, 11-Feb-21

1->Search in a 2-D Matrix
    //leetcode problem
    bool searchMatrix(vector<vector<int>>& matrix, int target)     {
        if(matrix.size()==0) return false;
        int r=matrix.size(),c=matrix[0].size();
        int low=0,high=(r*c)-1,mid;
        
        while(low<=high)
        {
            mid = (low + (high-low)/2);
            if(matrix[mid/c][mid%c] == target)
                return true;
            else if(matrix[mid/c][mid%c] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        return false;
    }
    //GfG
int search(int mat[4][4], int n, int x)
{
    if (n == 0)
        return -1;
   
    int smallest = mat[0][0], largest = mat[n - 1][n - 1];
    if (x < smallest || x > largest)
        return -1;
   
    // set indexes for top right element
    int i = 0, j = n - 1; 
    while (i < n && j >= 0) 
    {
        if (mat[i][j] == x) 
        {
            cout << "n Found at "
                 << i << ", " << j;
            return 1;
        }
        if (mat[i][j] > x)
            j--;
       
        // Check if mat[i][j] < x
        else
            i++;
    }
 
    cout << "n Element not found";
    return 0;
}

3-> pow(x,n)

    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn<0) nn = -1 * nn;
        while(nn)
        {
            if(nn%2)
            {
                ans *= x;
                nn -= 1;
            }
            else
            {
                x *= x;
                nn /= 2;
            }
        }
        if(n<0) ans = double(1.0)/double(ans);
        return ans;
    }

4-> Majority ele N/2
    //moore voting algo
    int majorityElement(vector<int>& nums) {
        
        int el=0;
        int cnt=0;
        
        for(auto num:nums)
        {
            if(cnt == 0)
                el = num;
            if(num == el) 
                cnt+=1;
            else
                cnt-=1;
        }
        return el;
    }

5-> Majority ele N/3
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1,num2=-1,c1=0,c2=0;
        vector<int> res;
        
        for(auto num:nums)
        {
            if(num == num1)
                c1++;
            else if(num == num2)
                c2++;
            else if(c1 == 0)
            {
                num1 = num;
                c1=1;
            }
            else if(c2 == 0)
            {
                num2 = num;
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        c1=c2=0;
        
        for(auto num:nums)
        {
            if(num == num1) c1++;
            else if(num == num2) c2++;
        }
        
        if(c1>nums.size()/3) res.push_back(num1);
        if(c2>nums.size()/3) res.push_back(num2);
        
        return res;
        
    }
};

6-> Unique path
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
        
    }
//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 4, 12-Feb-21
1-> Two sum
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            int numbertofind = target - nums[i];
            
            if(map.find(numbertofind) != map.end())
            {
                result.push_back(map[numbertofind]);
                result.push_back(i);
            }
            
            map[nums[i]] = i;
        }
        return result;
    }

2-> 4 sum
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n == 0) return res;
        sort(nums.begin() , nums.end());
        
        for(int i=0;i<n;i++)
        {
            int target_3 = target - nums[i];
            
            for(int j=i+1;j<n;j++)
            {
                int target_2 = target_3 - nums[j];
                int left = j+1;
                int right = n-1;
                
                while(left<right)
                {
                    int two_sum = nums[left]+nums[right];
                    if(two_sum < target_2) left++;
                    else if(two_sum > target_2) right--;
                    else
                    {
                         vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        res.push_back(quad);
                        
                    while(left < right && nums[left] == quad[2]) ++left;
                    while(left < right && nums[right] == quad[3]) --right;
                        
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) ++j;
            }
            while(i+1<n&&nums[i]==nums[i+1])++i;
        }
        return res;
    }

3-> longest consecutive sum 
    int longestConsecutive(vector<int>& nums) {
        set<int> set;
        int longest = 0;
        for(auto num : nums)
            set.insert(num);
        for(auto num : nums)
        {
            if(!set.count(num-1))
            {
                int currentstreak = 1;
                int currnum = num;
                
                while(set.count(currnum+1))
                {
                    currnum++;
                    currentstreak++;
                }
                        
                longest = max(longest,currentstreak);

            }
        }
        return longest;
    }

4-> Largest subarray with sum 0
int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> map;
    int sum = 0;
    int maxi = 0;
    
    for(int i=0;i<n;i++)
    {
        sum += A[i];
        if(sum == 0)
            maxi = i+1;
        else
        {
            if(map.find(sum) != map.end())
            {
                maxi = max(maxi,i-map[sum]);
            }
            else
                map[sum] = i;
        }
    }
    return maxi;
}

5-> Subarray sum equals K 
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> map;
        int n = nums.size();
        int currsum =0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            currsum+=nums[i];
            if(currsum == k)
                cnt++;
            if(map.find(currsum-k) != map.end())
            {
                cnt += (map[currsum-k]);
            }
            map[currsum]++;
        }
        return cnt;
        
    }

6-> longest substring without repeating
    int lengthOfLongestSubstring(string s) {
     
        set<int> set;
        int i=0,j=0,count=0;
        while(j<s.length())
        {
            if(set.find(s[j]) == set.end())
            {
                set.insert(s[j++]);
                count = max(count , j-i);
            }
            else
                set.erase(s[i++]);
        }
        return count;
        
    }

7->Count Subarrays with Xor as K
    int cntSubarray(vector<int> arr,int K)
    {
        int xoor = 0;
        int count = 0;
        unordered_map<int,int> freq;
        for(int num:arr)
        {
            xoor = xoor ^ num;
            if(xoor == K)
                count++;
            if(freq.find(xoor^K) != freq.end())
            {
                count += freq[xoor^K];
            }

            freq[xoor]++;
        }
        return count;
    }

//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 5, 13-Feb-21

1-> reverse a LL 
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head,*prev = NULL,*next;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;   
    }

        ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        ListNode *revnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return revnode;
        }

2->Middle of LL 

    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

3->Merge sorted LL 
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy;
        while(l1 && l2)
        {
           int a = l1->val, b = l2->val;
            if(a < b)
            {
                l3->next = new ListNode(a);
                l3 = l3->next;
                l1 = l1->next;
            }
            else
            {
                l3->next = new ListNode(b);
                l3 = l3->next;
                l2 = l2->next;
            }
        }
        l3->next = l1?l1:l2;
        return dummy->next;
    }

4->Remove nth node from LL 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *headnew = dummy;
        while(headnew != NULL)
        {
            length++;
            headnew = headnew->next;
        }
        headnew = dummy;
        length = length-n-1;
        while(length>0)
        {
            length--;
            headnew = headnew->next;
        }
        headnew->next = headnew->next->next;
        return dummy->next;
    }

5-> Shortest path in binary matrix 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        if(grid[0][0] == 1 || grid[row-1][col-1] == 1)
            return -1;
        queue<pair<int,int>> queue;
        queue.push(make_pair(0,0));
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        grid[0][0] = 1;
        while(!queue.empty())
        {
            auto curr = queue.front();
            int x = curr.first, y = curr.second;
            if(x == row-1 && y==row-1) return grid[x][y];
            
            for(auto direction : directions)
            {
                int nx = x + direction[0];
                int ny = y + direction[1];
                if(nx>=0 && nx<row && ny>=0 && ny<col && grid[nx][ny] == 0)
                {
                    queue.push(make_pair(nx,ny));
                    grid[nx][ny] = grid[x][y]+1;
                }
            }
            queue.pop();
        }
        return -1;
    }

6-> Minimum path sum 
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i=1;i<n;i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j] = min(dp[i-1][j] , dp[i][j-1])+grid[i][j];
        return dp[m-1][n-1];
        
        
    }

7-> Add two numbers
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyhead = new ListNode(0);
        ListNode *res = dummyhead;
        ListNode *p = l1 , *q = l2;
        int carry = 0;
        while(p || q)
        {
            int x = (p==NULL)?0:p->val;
            int y = (q==NULL)?0:q->val;
            int sum = x+y+carry;
            res->next = new ListNode(sum%10);
            carry = sum/10;
            res=res->next;
            if(p!=NULL)p=p->next;
            if(q!=NULL)q=q->next;
           
        }
        if(carry>0)
            res->next = new ListNode(carry);

        return dummyhead->next;
    }

//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 6, 14-Feb-21

1-> Intersection of Two LL 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *a=headA,*b=headB;
        while(a!=b)
        {
            a = a==NULL?headB:a->next;
            b = b==NULL?headA:b->next;
        }
        return a;
    }

2->Cycle in LL 
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode*slow=head,*fast=head;
        while(fast != NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }

3->Palindrome LL 
    ListNode*reverse(ListNode*head)
    {
        if(head == NULL || head->next==NULL) return head;
        ListNode*revhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return revhead;
    }
    bool isPalindrome(ListNode* head) {
        
        stack<int> s;
        ListNode*slow=head,*fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)
            slow = slow->next;
        while(slow)
        {
            int x = s.top(); s.pop();
            if(x != slow->val) return false;
            slow = slow->next;
        }
        return true;
    }

//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 7, 15-Feb-21

2->3 sum 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
              if(i==0 || nums[i]!=nums[i-1])
              {
            int left = i+1;
            int right = n-1;
            while(left < right)
            {
                int tempsum = nums[left] + nums[right] + nums[i];
                if(tempsum<0)
                    left++;
                else if(tempsum>0)
                    right--;
                else
                {
                    vector<int>temp{nums[i],nums[left],nums[right]};
                    res.push_back(temp);
                    while(left<right && nums[left]==nums[left+1])left++;
                while(left<right&&nums[right]==nums[right-1])right--;
                    left++;
                    right--;                    
                }
            }
        }
    }
        return res;
}
 3->remove duplicates from sorted array 
         int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int i=0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                nums[++i] = nums[j]; 
            }
            
        }
        return i+1;
    }
4-> Max consecutive ones 
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
                cnt++;
            else
                cnt = 0;
             maxi = max(maxi,cnt);
        }
        return maxi;
    }

//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 8, 16-Feb-21

1->Letter case permutation 
   
    vector<string>ans;
    void solve(string curr,string s, int i){
        // if end of the string is reached
        if(i==s.length()){
            ans.push_back(curr); // push the current "curr" string to ans
            return;
        }
        
        if(isdigit(s[i])){ // case 1
            curr.push_back(s[i]);
            solve(curr,s,i+1);
        }
        else{ // case 2
            //sub case 1, considering lower case
            string c1=curr;
            c1.push_back(tolower(s[i]));
            solve(c1,s,i+1);
            
            //sub case 2, considering upper case
            string c2=curr;
            c2.push_back(toupper(s[i]));
            solve(c2,s,i+1);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        ans.clear();
        solve("",S,0);
        return ans;
    }
};

2-> Shortest path in Binary Matrix 
   int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        if(grid[0][0] == 1 || grid[row-1][col-1] == 1)
            return -1;
        queue<pair<int,int>> queue;
        queue.push(make_pair(0,0));
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        grid[0][0] = 1;
        while(!queue.empty())
        {
            auto curr = queue.front();
            int x = curr.first, y = curr.second;
            if(x == row-1 && y==row-1) return grid[x][y];
            
            for(auto direction : directions)
            {
                int nx = x + direction[0];
                int ny = y + direction[1];
                if(nx>=0 && nx<row && ny>=0 && ny<col && grid[nx][ny] == 0)
                {
                    queue.push(make_pair(nx,ny));
                    grid[nx][ny] = grid[x][y]+1;
                }
            }
            queue.pop();
        }
        return -1;
    }

3->N meeting in a room
struct meeting{
    int end;
    int start;
    int pos;
};

bool comp(meeting m,meeting n)
{
    if(m.end < n.end) return true;
    else if(m.end > n.end) return false;
    else if(m.pos < n.pos) return true;
    return false;
}
int maxMeetings(int start[], int end[], int n) {

    vector<int> answer;
    meeting m[n];
    for(int i=0;i<n;i++)
    {
        m[i].start = start[i];
        m[i].end = end[i];
        m[i].pos  = i+1;
    }
    
    sort(m , m+n , comp);
    int limit = m[0].end;
    answer.push_back(m[0].pos);
    for(int i=1;i<n;i++)
    {
        if(m[i].start > limit)
        {
            limit = m[i].end;
            answer.push_back(m[i].pos);
        }
    }
    
    // for(int n:answer)
    //     cout<<n<<" ";
    return answer.size();
}

4->Contanier with most water 
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;
        int maxarea=0;
        while(left<right)
        {
            maxarea = max(maxarea , min(height[left],height[right])*(right-left));
            if(height[left] > height[right])
            {
                right--;
            }
            else if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                left++;
                right--;
            }
        }
        return maxarea;
    }

5-> Minimum number of platforms 

// Returns minimum number of platforms reqquired
int findPlatform(int arr[], int dep[], int n)
{
	// Sort arrival and departure arrays
	sort(arr, arr + n);
	sort(dep, dep + n);

	// plat_needed indicates number of platforms
	// needed at a time
	int plat_needed = 1, result = 1;
	int i = 1, j = 0;

	// Similar to merge in merge sort to process
	// all events in sorted order
	while (i < n && j < n) {
		// If next event in sorted order is arrival,
		// increment count of platforms needed
		if (arr[i] <= dep[j]) {
			plat_needed++;
			i++;
		}

		// Else decrement count of platforms needed
		else if (arr[i] > dep[j]) {
			plat_needed--;
			j++;
		}

		// Update result if needed
		if (plat_needed > result)
			result = plat_needed;
	}

	return result;
}

//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 9, 17-Feb-21

1-> Combination sum 1
class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
2-> Combination Sum 2
class Solution {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum2(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
    }
};
3-> Subset 1
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        bt(res,temp,nums,0);
        return res;
    }
    void bt(vector<vector<int>>&res,vector<int>tmp,vector<int>nums,int ind)
    {
        res.push_back(tmp);
        for(int i=ind;i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            bt(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
4-> Subset 2
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin() , nums.end());
        bt(res,temp,nums,0);
        return res;
    }
    void bt(vector<vector<int>>&res,vector<int>tmp,vector<int>nums,int ind)
    {
        res.push_back(tmp);
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            bt(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
5-> Palindrome Partioning 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pars;
        vector<string> par;
        dfs(pars,par,s,0);
        return pars;
    }
    void dfs(vector<vector<string>>&pars,vector<string>par,string s,int start)
    {
        if(start == s.length())
        {
            pars.push_back(par);
            return;
        }
        else
        {
            for(int i=start;i<s.length();i++)
            {
                if(ispalim(s,start,i))
                   {
                    par.push_back(s.substr(start,i-start+1));
                    dfs(pars,par,s,i+1);
                    par.pop_back();
                   }
            }
        }
    }
    bool ispalim(string &s,int l,int r)
    {
        while(l<r)
        {
            if(s[l++] != s[r--])
                return false;
        }
            return true;
    }
6-> Word Pattern 
public boolean wordPattern(String pattern, String str) {
        String[] arr= str.split(" ");
        HashMap<Character, String> map = new HashMap<Character, String>();
        if(arr.length!= pattern.length())
            return false;
        for(int i=0; i<arr.length; i++){
            char c = pattern.charAt(i);
            if(map.containsKey(c)){
                if(!map.get(c).equals(arr[i]))
                    return false;
            }else{
                if(map.containsValue(arr[i]))
                    return false;
                map.put(c, arr[i]);
            }    
        }
        return true;
    }
//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 10, 18-Feb-21 

1-> Arithmatic slices 
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int n = A.size();
        if(n<3) return 0;
        vector<int> dp(n);
        if(A[1]-A[0] == A[2]-A[1]) dp[2] = 1;
        int result = dp[2];
        
        for(int i=3;i<n;i++)
        {
            if(A[i-1]-A[i-2] == A[i]-A[i-1])
            {
                dp[i] = dp[i-1]+1;
            }
            result += dp[i];
        }
        
        return result;
    }
2->N-queens
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nqueen(n,string(n,'.'));
        solveNqueen(res,nqueen,n,0);
        return res;
    }
    
    void solveNqueen(vector<vector<string>>&res,vector<string>&nqueen,int &n,int row)
    {
        if(row == n)
        {
            res.push_back(nqueen);
            return;
        }
        else
        {
            for(int col=0;col!=n;col++)
            {
                if(isvalid(nqueen,row,col,n))
                {
                    nqueen[row][col] = 'Q';
                    solveNqueen(res,nqueen,n,row+1);
                    nqueen[row][col] = '.';
                }
            }
        }
    }
    bool isvalid(vector<string>&nqueen,int row,int col,int &n)
    {
        for(int i=0;i!=row;i++)
            if(nqueen[i][col]=='Q')
                return false;
        for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j)
            if(nqueen[i][j]=='Q')
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nqueen[i][j] == 'Q')
                return false;
        return true;
    }
//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 11, 23-Feb-21

1-> Longest Word in Dict through Deleting 
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        int maxcnt = -1;
        int cnt = 0;
        sort(d.begin(),d.end()) ;
        for(auto str:d)
        {
           if(iscorrect(str,s))
           {
             if(str.size()>res.size() || (str.size()==res.size() && str<res))
               res = str;
           }
        }
        return res;
    }
    
    bool iscorrect(string word,string str)
    {
        int i=0,j=0;
        while(i<word.length() && j<str.length())
        {
            if(word[i] == str[j])
                i++;
            j++;
        }
        
        return i == word.size();
    }

2->Find the element that appears once in sorted array, and rest element appears twice (Binary search) 
    int singleNonDuplicate(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        
        while(left<right)
        {
            int mid = (right+left)/2;
            
            if((mid%2==0 and nums[mid]==nums[mid+1]) or (mid%2==1 and nums[mid]==nums[mid-1]))
                left = mid+1;
            else
                right = mid;
        }
        return nums[left];
    }

3->Median of Two sorted array 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //if input1 length is greater than switch them so that input1 is smaller than input2.
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int x = nums1.size();
        int y = nums2.size();
        int left = 0;
        int right = x;
        while(left<=right)
        {
            int positionX = (left+right)/2;
            int positionY = (x+y+1)/2 - positionX;
             //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
            //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
            int maxLeftX = (positionX==0)?INT_MIN:nums1[positionX-1];
            int minRightX = (positionX==x)?INT_MAX:nums1[positionX];
            
            int maxLeftY = (positionY==0)?INT_MIN:nums2[positionY-1];
            int minRightY = (positionY==y)?INT_MAX:nums2[positionY];
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX)
            {
                //We have partitioned array at correct place
                // Now get max of left elements and min of right elements 
                //to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
                if((x+y)%2==0) 
                    return (double)(max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2;
                else
                    return (double)max(maxLeftY,maxLeftX);
            }
            else if(maxLeftX > minRightY)//we are too far on right side for partitionX. Go on left side.
                right = positionX-1;
            else//we are too far on left side for partitionX. Go on right side.
                left = positionX+1;
        }
        return 1.0;
    }

//*************************************************************************************************************************
//*************************************************************************************************************************
DAY 13, 24-Feb-21

1->Implement Queue using stack 
 /** Push element x to the back of queue. */
    void push(int x) {
        // if(first.empty())
        // {
        //     first.push(x);
        //     return;
        // }
        while(!first.empty())
        {
            int i=first.top(); first.pop();
            second.push(i);
        }
        second.push(x);
        while(!second.empty())
        {
            int i=second.top();second.pop();
            first.push(i);
        }
    }

2->Implement Stack using queue 
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

3-> Score of parenthesis
int scoreOfParentheses(string S)
{
    stack<int> m_stack;
    m_stack.push(0); // to keep the total score
    for(char c:S){
        if(c=='(')
            m_stack.push(0); //When meets '(', just push a zero to stack
        else{
            int tmp=m_stack.top(); //  balance the last '(', it stored the score of inner parentheses
            m_stack.pop();
            int val=0;
            if(tmp>0) // not zero means inner parentheses exists and double it
                val=tmp*2;
            else // zero means no inner parentheses, just using 1
                val=1;
            m_stack.top()+=val; // pass the score of this level to parent parenthese
        }   
    }
    return m_stack.top();
}