class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int cnt=0;
        int maxcnt=0;
        int i=0;
        int j=0;
        while(i<arr.size() && j<dep.size())
        {
            if(arr[i]<=dep[j])
            {
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxcnt=max(maxcnt,cnt);
        }
        return maxcnt;
    }
};
