/***
 * Sort the array. For each i, set T = target - A[i], the remaining target. We can try using a two-pointer technique to find A[j] + A[k] == T. This approach is the natural 
 continuation of trying to make the two-pointer technique we know from previous problems, work on this problem.

Because some elements are duplicated, we have to be careful. In a typical case, the target is say, 8, and we have a remaining array (A[i+1:]) of [2,2,2,2,3,3,4,4,4,5,5,5,6,6]. 
We can analyze this situation with cases.

Whenever A[j] + A[k] == T, we should count the multiplicity of A[j] and A[k]. In this example, if A[j] == 2 and A[k] == 6, the multiplicities are 4 and 2, and the total number 
of pairs is 4 * 2 = 8. We then move to the remaining window A[j:k+1] of [3,3,4,4,4,5,5,5].

As a special case, if A[j] == A[k], then our manner of counting would be incorrect. If for example the remaining window is [4,4,4], there are only 3 such pairs. In general, 
when A[j] == A[k], we have (M*(M-1))/2 pairs (j,k) (with j < k) that satisfy A[j] + A[k] == T, where MM is the multiplicity of A[j] (in this case M=3M=3).
*/

     int threeSumMulti(vector<int>& arr, int target) {
        int size = arr.size();
        long long ans = 0;
        int M = 1000000007;
        sort(arr.begin() , arr.end());
        for(int i=0;i<size;i++) {
            // We'll try to find the number of i < j < k
            // with A[j] + A[k] == T, where T = target - A[i].

            // The below is a "two sum with multiplicity".
            int T = target - arr[i];
            int j = i+1 , k = size-1;
            
            while(j < k) {
                 // These steps proceed as in a typical two-sum.
                if(arr[j] + arr[k] < T)
                    j++;
                else if(arr[j] + arr[k] > T)
                    k--;
                else if(arr[j] != arr[k]) {// We have A[j] + A[k] == T.
                    // Let's count "left": the number of A[j] == A[j+1] == A[j+2] == ...
                    // And similarly for "right".
                    int left = 1 ,right = 1;
                    while( arr[j] == arr[j+1])
                    {
                        left++;
                        j++;
                    }
                    while( arr[k] == arr[k-1])
                    {
                        right++;
                        k--;
                    }
                    ans += left*right;
                    ans %= M;
                    j++;
                    k--;
                }
                else {
                    // M = k - j + 1
                    // We contributed M * (M-1) / 2 pairs.
                    int m = k-j+1;
                    ans += (m*(m-1))/2;
                    ans %= M;
                    break;
                }
            }
        }
        return (int)ans;
    }