    /*
    https://leetcode.com/problems/max-number-of-k-sum-pairs/
    
    Hints -> 
    1. The abstract problem asks to count the number of disjoint pairs with a given sum k.
    2. For each possible value x, it can be paired up with k - x.
    3. The number of such pairs equals to min(count(x), count(k-x)), unless that x = k / 2, where the number of such pairs will be floor(count(x) / 2).
    
    Using Map for storing count of each element in array.
    
    nums = [2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2]
    
    k = 6
    
    map = 2 -> 6
          5 -> 1
          4 -> 7
          1 -> 4
          3 -> 2
    
    Looping through left side of map, i.e elements of array
     
        let x = k - left
        
        using Hint 3
        
        if( x is not exactly half of k)
            pairs count = minimum of map[x] or map[k-x]
            make map[x] and map[k-x] = 0
            because we are allowed to use each element one time only
        
        else if( x is exactly half of k)
            pairs count = floor of (map[x])
            make map[x] = 0
    
    return pairs count
    */
    int maxOperations(vector<int>& nums, int k) {
        int x , cnt=0;
        int n = nums.size();
        map<int,int> map;
        
        for(int i=0;i<n;i++) {
            map[nums[i]]++;
        }
        
        for(auto i : map) {
            x = k - i.first;
            if( x!=k/2) {
                cnt += min(map[x] , map[k-x]);
                    map[x] = 0;
                    map[k-x] = 0;
            }
            else if(x==k/2) {
                cnt += floor(map[x]/2);
                map[x] = 0;

            }
        }
        return cnt;
        
    }
