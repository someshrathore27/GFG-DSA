
struct meeting{
    int starttime;
    int endtime;
};
    bool compare(meeting m1,meeting m2)
    {
        return m1.endtime<m2.endtime;
    }
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int ans=0;
        int n=start.size();
        vector<meeting>meets(n);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            meets[i].starttime=start[i];
            meets[i].endtime=end[i];
        }
        sort(meets.begin(),meets.end(),compare);
        int currtime=-1;
        for(int i=0;i<n;i++)
        {
            if(meets[i].starttime>currtime)
            {
                currtime=meets[i].endtime;
                cnt++;
            }
        }
        return cnt;
    }
};