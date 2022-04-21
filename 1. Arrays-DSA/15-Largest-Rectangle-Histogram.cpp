    Video Ref-> https://www.youtube.com/watch?v=ZmnqCZp9bBs
    Question Link-> https://leetcode.com/problems/largest-rectangle-in-histogram/

    1. Add to stack if current value is greater then or equal to the top of the stack
    2. Otherwise keep removing from stack till a number whaich is smaller than or equal then current is found
    3. Calculate area everytime you remove from stack
        if(stack.isEmpty())
            area = input[top] * i;
        else
            area = input[top] * (i-top-1);

    int largestRectangleArea(vector<int>& heights) {
              
        stack<int> stack;
        int area=0,maxarea=0,top=0,i;
        
        for( i=0;i<heights.size();)
        {
            if(stack.empty() || heights[i]>=heights[stack.top()])
            {
                stack.push(i);
                i++;
            }
            else
            {
                top = stack.top();
                stack.pop();
                if(stack.empty())
                {
                    area = heights[top] * i;    
                }
                else
                {
                    area = heights[top] * (i-stack.top()-1);
                }
                
                maxarea = area>maxarea?area:maxarea;
            }
        }
        
        while(!stack.empty())
        {
            top = stack.top();
            stack.pop();
            if(stack.empty())
            {
                area = heights[top] * i;
            }
            else
            {
                area = heights[top] * (i-stack.top()-1);
            }
            maxarea = area>maxarea?area:maxarea;
        }
        
        return maxarea;
    }
