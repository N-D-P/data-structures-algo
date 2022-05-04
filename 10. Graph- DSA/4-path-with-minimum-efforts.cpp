// https://leetcode.com/problems/path-with-minimum-effort/

/*
    Video ref -> https://www.youtube.com/watch?v=FabSLaGu0NI&t=863s

*/
int minimumEffortPath(vector<vector<int>> &heights)
{

    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int r = heights.size();
    int c = heights[0].size();

    vector<vector<int>> efforts(r, vector<int>(c, INT_MAX));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {0, 0}}); // { efforts , {row,col}}

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        int effort = x.first;
        int row = x.second.first;
        int col = x.second.second;

        if (row == r - 1 and col == c - 1)
            return effort;

        if (effort > efforts[row][col])
            continue;

        for (auto dir : dirs)
        {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (newRow >= 0 and newRow < r and newCol >= 0 and newCol < c)
            {
                int newEffort = max(effort, abs(heights[newRow][newCol] - heights[row][col]));
                if (efforts[newRow][newCol] > newEffort)
                {
                    pq.push({newEffort, {newRow, newCol}});
                    efforts[newRow][newCol] = newEffort;
                }
            }
        }
    }

    return -1;
}
