//Question Link -> https://leetcode.com/problems/top-k-frequent-elements/

    static bool cmp(pair<int,int> &a , pair<int,int> &b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> map;
        
        for(int i=0;i<nums.size();i++) {
            map[nums[i]]++;
        }
        
        vector<pair<int, int> > A;

        for (auto& it : map) {
            A.push_back(it);
        }
        
        sort(A.begin() , A.end() , cmp);
        
        vector<int> res;
        for(int i=0;i<k;i++)
        {
            res.push_back(A[i].first);
        }
        
        return res;
        
    }