class Solution {
public:
    string isKSortedArray(int arr[], int n, int k) 
    {
        vector<int> sortedArr(arr, arr + n);
        sort(sortedArr.begin(), sortedArr.end());
        
        for (int i = 0; i < n; i++) 
        {
            auto it = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]);
            int sortedPos = it - sortedArr.begin();
            
            if (abs(i - sortedPos) > k) {
                return "No";
            }
        }
        
        return "Yes";
    }
};