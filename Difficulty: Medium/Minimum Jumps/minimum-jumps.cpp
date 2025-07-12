class Solution {
  public:
    int minJumps(vector<int>& arr) {
        if(arr.size()==0 || arr[0]==0)
        {
            return -1;
        }
        int l=0;
        int r=0;
        int jumps=0;
        while(r<arr.size()-1)
        {
            int farthest=INT_MIN;
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,i+arr[i]);
            }
            if (farthest == r)
            {
                return -1;
            }
            l=r+1;
            r=farthest;
            jumps=jumps+1;
        }
        return jumps;
    }
};
