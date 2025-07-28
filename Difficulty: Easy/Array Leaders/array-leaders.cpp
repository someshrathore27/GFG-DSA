

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        if(arr.size()==1)
        {
            return arr;
        }
        int e=arr.size()-1;
        int maxi=arr[e];
        vector<int>ans;
        ans.push_back(maxi);
        for(int i=e-1;i>=0;i--)
        {
            if(arr[i]>=maxi)
            {
                ans.push_back(arr[i]);
                maxi=max(maxi,arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    
    }
};