/**
 * Question Link -> https://leetcode.com/problems/merge-intervals/
 * Explanation -> https://www.youtube.com/watch?v=2JzRBPFYbKE&list=PLByG0Le9gW1ukPzWdArXFN8iHh5OgUWOV&index=3
 * Side case : [[1,4],[2,3]]
*/

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) 
            return intervals;
        vector<vector<int>> res;
        sort(intervals.begin() , intervals.end());
        res.push_back({intervals[0][0] , intervals[0][1]});
        for(int i=1;i<intervals.size();i++) {
            vector<int> temp = res.back();
            int strt = intervals[i][0];
            int endd = intervals[i][1];
            if(strt <= temp[1]) {
                if(endd > temp[1])   // For side case
                    res.back()[1] = endd;
            }
            else {
                res.push_back({strt ,endd});
            }
        }
        return res;
    }