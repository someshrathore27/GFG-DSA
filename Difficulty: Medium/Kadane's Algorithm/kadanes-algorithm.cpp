class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n=arr.size();
        if(n==0)
        {
            return 0;
        }
        int sum=arr[0];
        int maxsum=arr[0];
        for(int i=1;i<n;i++)
        {
            sum=max(sum+arr[i],arr[i]);
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};