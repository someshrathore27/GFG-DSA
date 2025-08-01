class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b) 
        {
            return a[1] < b[1];
        });
        
        int count = 0;
        int last_end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); ++i) 
        {
            if (intervals[i][0] < last_end) 
            {
                count++;
            } 
            else 
            {
                last_end = intervals[i][1];
            }
        }
        
        return count;
    }
};
