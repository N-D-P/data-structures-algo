/*
Using max heap is equivalent to sorting on every iteration

Intialise priority_queue with stones array, so that they are in DESC order in queue
Next, while the size of queue is greater then 1 we will perform below steps
Take the largest number from queue in first then pop and again take second largest in second then again pop
Popping first two elements will remove the two largest elements from queue
Store difference os first and second in res
push res back in queue
Reason for pushing res back in queue is that, we should not worry about sorting, heap will take care and res will be placed in its appropriate position
*/

 int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin() , stones.end()); //Intialize queue with stones array
        while(pq.size() > 1) {             //Running loop till queue has one element 
            int first = pq.top();           // Largest Element in queue
            pq.pop();
            int second = pq.top();     //Second Largest element in queue
            pq.pop();
            int res = first - second;   //Get Difference
            pq.push(res);                  // Push back into queue, so that it will be placed in appropriate postion, 
        }                                         // Pushing res back in pq will take care of sorting, res will be placed in its appropriate position
        
        return pq.top();
    }