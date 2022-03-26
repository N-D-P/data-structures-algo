Subarray with given sum
Given an unsorted array A of size N that contains only non-negative integers,
find a continuous sub-array which adds to a given number S
I have used two pointers method. 
Main idea is that to check currsum for a range defined by L and R 
if currsum is less than S then add arr[R] to curr sum and increment R
else if currsum is more than S then subtract arr[L] from currsum and decrement L
else store L and R in RES vector.
vector<int> subarraySum(int arr[], int n, int s){
    
    int currsum=arr[0],l=0,r=0;
    vector<int> res;
    while(l<n)
    {
        if(currsum<s)
        {
            r++;
            currsum += arr[r];
        }
        else if(currsum>s)
        {
            currsum -= arr[l];
            l++;
        }
        else
        {
            res.push_back(l+1);
            res.push_back(r+1);
            return res;
        }
    }
    res.push_back(-1);
    return res;
    
}

Count the triplets
Given an array of distinct integers. The task is to count all the triplets such that 
sum of two elements equals the third element.

MAIN IDEA : 
 Try two pointer algorithm
Step1: Maintain two pointer one starting from 0 and other one from n-2.
Step2: Check if sum of two such elements equal to the (n-1)th element of array 
if so then increase count and increment one pointer ahead by 1 and decerement other pointer by 1.
Step3: If sum is less, then move starting pointer ahead only
Step4: if sum is more, then decrement end pointer by 1 only.
int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    sort(arr, arr + n,greater<int>()); 
		int  ans = 0;

		for(int i=0;i<n;i++)
		{
		    int l = 0;
		    int r = n-1;
		    
		    while(l<r)
		    {
		        if(arr[i] == arr[l] + arr[r])
		        {
		            ans++;
		            l++;
		            r--;
		        }
		        else if(arr[i] < arr[l]+arr[r])
		            l++;
		        else
		            r--;
		    }
		}

		return ans;
	}

Kadane's Algorithm

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


Merge Without Extra Space (NOT DONE)

Given two sorted arrays arr1[] and arr2[] of sizes N and M in non-decreasing order. 
Merge them in sorted order without using any extra space. 
Modify arr1 so that it contains the first N elements and modify arr2 so that it contains 
the last M elements.
 
void merge(int arr1[], int arr2[], int n, int m) 
{ 
    // code here 
    int i=n-1;
    int j=0;
    while(i>=0 && j<m)
    {
        if(arr1[i] >= arr2[j])
        {
            swap(arr1[i] , arr2[j]);
            i--; j++;
        }
        else break;
    }
    sort(arr1, arr1+n);
    sort(arr2 , arr2+m);
} 

Sort an array of 0s, 1s and 2s

Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Main Idea Take three pointers, start , end , index 
start will point zeroes, end will point twos, index for traversing. 
when we encounter 0 in index swap nums[start] and nums[index] and increment start and index. 
When we encounter 2 swap nums[end], nums[index], just decrement end, 'dont Increment index, 
as we don't know what is at nums[end], it could be zero,one or two

void sort012(int nums[], int n)
{
    // coode here 
    int start=0,end=n-1,index=0;
    if(n==0 || n==1) return;
    
    while(index<=end)
    {
        if(nums[index] == 0)
        {
            swap(nums[index++] , nums[start++]);
        }
        else if(nums[index] == 2)
        {
            swap(nums[index] , nums[end--]);
        }
        else
            index++;
    }
}

Rearrange Array Alternately
Given a sorted array of positive integers. Your task is to rearrange  the array elements 
alternatively 
i.e first element should be max value, second should be min value, third should be second max, 
fourth should be second min and so on.
YOUTUBE LINK = https://www.youtube.com/watch?v=ZRoVWxBngX0

void rearrange(long long *arr, int n) 
{ 
	
    // initialize index of first minimum and first 
	// maximum element 
    int mini = 0;
	int maxi = n-1;
    // store maximum element of array
	int maxe = arr[maxi]+1;
	
	
    // traverse array elements 
	for(int i=0;i<n;i++)
	{
        // at even index : we have to put maximum element 
	    if(i%2 == 0)
	    {
	        arr[i] = arr[i] + arr[maxi]%maxe * maxe;
	        maxi--;
	    }
        // at odd index : we have to put minimum element 
	    else
	    {
	        arr[i] = arr[i] + arr[mini]%maxe * maxe;
	        mini++;
	    }
	}
    // array elements back to it's original form 
	for(int i=0;i<n;i++)
	{
	    arr[i]/=maxe;
	}
	 
}

Longest Harmonious Subsequence

Given two arrays X[] and Y[] of positive integers, find number of pairs such that x^y > y^x 
where x is an element from X[] and y is an element from Y[].

Examples:

Input: X[] = {2, 1, 6}, Y = {1, 5} 
Output: 3 
Explanation: There are total 3 pairs where pow(x, y) is greater 
than pow(y, x) Pairs are (2, 1), (2, 5) and (6, 1)

Input: X[] = {10, 19, 18}, Y[] = {11, 15, 9} 
Output: 2 
Explanation: There are total 2 pairs where pow(x, y) is greater 
than pow(y, x) Pairs are (10, 11) and (10, 15)

The problem can be solved in O(nLogn + mLogn) time. The trick here is, if y > x then x^y > y^x with some exceptions. 

Following are simple steps based on this trick.  

Sort array Y[].
For every x in X[], find the index idx of smallest number greater than x (also called ceil of x) in Y[] 
using binary search or we can use the inbuilt function upper_bound() in algorithm library.
All the numbers after idx satisfy the relation so just add (n-idx) to the count.

Following are exceptions for x from X[] and y from Y[]  

If x = 0, then the count of pairs for this x is 0.
If x = 1, then the count of pairs for this x is equal to count of 0s in Y[].
x smaller than y means x^y is greater than y^x.
1.  x = 2, y = 3 or 4
2.  x = 3, y = 2


C++ program to finds the number of pairs (x, y) 
in an array such that x^y > y^x 

#include<bits/stdc++.h> 
using namespace std; 

// Function to return count of pairs with x as one element 
// of the pair. It mainly looks for all values in Y[] where 
// x ^ Y[i] > Y[i] ^ x 
int count(int x, int Y[], int n, int NoOfY[]) 
{ 
	// If x is 0, then there cannot be any value in Y such that 
	// x^Y[i] > Y[i]^x 
	if (x == 0) return 0; 

	// If x is 1, then the number of pais is equal to number of 
	// zeroes in Y[] 
	if (x == 1) return NoOfY[0]; 

	// Find number of elements in Y[] with values greater than x 
	// upper_bound() gets address of first greater element in Y[0..n-1] 
	int* idx = upper_bound(Y, Y + n, x); 
	int ans = (Y + n) - idx; 

	// If we have reached here, then x must be greater than 1, 
	// increase number of pairs for y=0 and y=1 
	ans += (NoOfY[0] + NoOfY[1]); 

	// Decrease number of pairs for x=2 and (y=4 or y=3) 
	if (x == 2) ans -= (NoOfY[3] + NoOfY[4]); 

	// Increase number of pairs for x=3 and y=2 
	if (x == 3) ans += NoOfY[2]; 

	return ans; 
} 

// Function to return count of pairs (x, y) such that 
// x belongs to X[], y belongs to Y[] and x^y > y^x 
int countPairs(int X[], int Y[], int m, int n) 
{ 
	// To store counts of 0, 1, 2, 3 and 4 in array Y 
	int NoOfY[5] = {0}; 
	for (int i = 0; i < n; i++) 
		if (Y[i] < 5) 
			NoOfY[Y[i]]++; 

	// Sort Y[] so that we can do binary search in it 
	sort(Y, Y + n); 

	int total_pairs = 0; // Initialize result 

	// Take every element of X and count pairs with it 
	for (int i=0; i<m; i++) 
		total_pairs += count(X[i], Y, n, NoOfY); 

	return total_pairs; 
} 

// Driver program 
int main() 
{ 
	int X[] = {2, 1, 6}; 
	int Y[] = {1, 5}; 

	int m = sizeof(X)/sizeof(X[0]); 
	int n = sizeof(Y)/sizeof(Y[0]); 

	cout << "Total pairs = " << countPairs(X, Y, m, n); 

	return 0; 
} 


Equilibrium Point

Given an array A of N positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
Input:
N = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: For second test case 
equilibrium point is at position 3 
as elements before it (1+3) = elements after it (2+2).

int equilibriumPoint(long long a[], int n) {

    // Sum of all array elements
    long long sum = 0;
    for (int i = 0; i < n; i++) 
       sum += a[i];

    // sum2 is used to store prefix sum
    long long sum2 = 0;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        
        // update suffix sum
        sum = sum - a[i];
        
        // Check if suffix and prefix 
        // sums are same
        if (sum2 == sum) {
            return (i + 1);
        }
        
        // Update prefix sum
        sum2 = sum2 + a[i];
    }
    return -1;
}

->Leaders in an array

Given an array A of positive integers. Your task is to find the leaders in the array. 
An element of array is leader if it is greater than or equal to all the elements to its right side. 
The rightmost element is always a leader.

vector<int> leaders(int a[], int n){
    // code here
    vector<int> res;
    int curmax=-1;
    for(int i=n-1;i>=0;i--)
    {
        curmax = max(a[i],curmax);
        if(curmax == a[i])
        res.push_back(curmax);
    }
    reverse(res.begin() , res.end());
    return res;
}