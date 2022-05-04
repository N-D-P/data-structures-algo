    /*
    Question -> https://leetcode.com/problems/min-cost-to-connect-all-points/
    Video Ref -> https://www.youtube.com/watch?v=f7JOBJIC-NA
    
    Using Prim's Algorithm.
    
    VISITED array stores indexes of points that are visited.
    
    PQ is MIN HEAP priority Queue, the syntax is unfamiliar to me, copied it from leetcode solution,
        generally we use only greater<int> to make MIN HEAP, but it must be diffrent in case of <pair<int,int>>
    
    Prim's Algo starts with one node, and using BFS it travese to node with minimum edge.
    and while doing this it keeps a track of visited nodes, so to not make loop in graph
    
    We will use Array for storing visited nodes, and a min heap for storing weigth of edge from currNode to every other
    node which is not visited.
    
    In while loop, starting from 0th point
        1. Mark i as visited,
        
        2. Loop through every points,
            And if that point is not visited,
                Push the {weight , index of univisited point} in MIN HEAP
                
        Now MIN HEAP will store the minimum weight on the TOP
        
        As we are pushing every unvisited node, there will be case where there is more than one
        weight associated with one index.
        
        To avoid popping duplicate node ->
        
        3. Pop from MIN HEAP till there's already a visited node
        
        4. Updated RES with MIN HEAP's top WEIGHT
        
        5. Update i so to pick that node as next element 
        
        6. Pop from MIN HEAP
    */
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() , connected = 0 , i = 0 , res = 0;
        vector<bool> visited(n);
        priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        while(++connected < n) {
            visited[i] = true;
            for(int j=0; j<n; j++) {
                if(!visited[j]) {
                    pq.push({abs( points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) , j});
                }
            }
            while(visited[pq.top().second])
                pq.pop();
            res += pq.top().first;
            i = pq.top().second;
            pq.pop();

        }
        
        return res;
        
    }
