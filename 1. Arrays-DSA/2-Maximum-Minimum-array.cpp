    vector<int> getMinMax(vector<int>&arr , int n)
    {
        vector<int> result(2); //result array, 0-> max | 1->min
        int i; //index

        // If array has even number of elements 
        // then initialize the first two elements 
        // as minimum and maximum
        if(n%2 == 0)
        {
            if(arr[0] > arr[1])
            {
                result[0] = arr[0];
                result[1] = arr[1];
            }
            else
            {
                result[0] = arr[1];
                result[1] = arr[0];
            }
            //set starting index for loop
            i = 2;
        }
        // If array has odd number of elements 
        // then initialize the first element as 
        // minimum and maximum
        else
        {
            result[0] = result[1] = arr[0];
            //set starting index for loop
            i = 1;
        }
        while(i < n-1)
        {
            if(arr[i] > arr[i+1])
            {
               result[0] = max(arr[i],result[0]);
               result[1] = min(arr[i+1],result[1]);
            }
            else
            {
                result[0] = max(arr[i+1],result[0]);
                result[1] = min(arr[i],result[1]);
            }
            //Increment the index by 2 as
            //two elements are processed in loop
            i += 2;
        }
        return result;
    }
