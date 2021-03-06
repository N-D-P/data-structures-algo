    Question Link -> https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

    Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or 
    decreasing them by K only once. After modifying, height should be a non-negative integer. 
    Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower

    Example 1:
    Input:
    K = 2, N = 4
    Arr[] = {1, 5, 8, 10}
    Output:
    5
    Explanation:
    The array can be modified as 
    {3, 3, 6, 8}. The difference between 
    the largest and the smallest is 8-3 = 5.

    int getMinDiff(int arr[], int n, int k) {

       vector<int> array;
       sort(arr,arr+n);
       
       int answer = arr[n-1]-arr[0];     
       int smallest = arr[0]+k;
       int largest = arr[n-1]-k;
       int minn=0,maxx=0;
       
       for(int i=0;i<n-1;i++)
       {
            minn = min(smallest , arr[i+1]-k);
            maxx = max(largest , arr[i]+k); //we choose immediate pair because that is the minimum diff we can get for current pair in sorted array
            if(minn < 0) continue;
            answer = min(answer , maxx-minn);
       }
      return answer;
    }
