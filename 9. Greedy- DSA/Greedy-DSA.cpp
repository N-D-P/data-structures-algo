Greedy-DSA

1-> N meetings in one room (There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] 
                            is start time of meeting i and end[i] is finish time of meeting i.)

    video_link : https://www.youtube.com/watch?v=AsbDqOauGZE

    static bool comp(pair<int,int> a , pair<int,int> b)
    {
        if(a.second == b.second) return a.first<b.first;
        
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> meeting(n);
        
        for(int i=0;i<n;i++) meeting[i] = {start[i] , end[i]};
        
        sort(meeting.begin() , meeting.end() , comp);
        
        int i=0 , j=1 , cnt=1;
        
        while(j<n)
        {
            if(meeting[i].second < meeting[j].first)
            {
                i=j;
                j++;
                cnt++;
            }
            else
            {
                j++;
            }
        }
        return cnt;
    }


