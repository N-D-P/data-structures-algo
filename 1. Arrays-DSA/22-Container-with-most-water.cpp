/**
 * Question Link -> https://leetcode.com/problems/container-with-most-water/
*/

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