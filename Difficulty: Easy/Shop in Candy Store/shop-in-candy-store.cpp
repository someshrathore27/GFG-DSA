class Solution {
public:
    vector<int> candyStore(int candies[], int N, int K) {
        sort(candies, candies + N);

        int minsum = 0, maxsum = 0;
        int i = 0, j = N - 1;
        while (i <= j)
        {
            minsum += candies[i++];
            j -= K;
        }
        i = 0, j = N - 1;
        while (i <= j) 
        {
            maxsum += candies[j--];
            i += K;
        }

        return {minsum, maxsum};
    }
};
