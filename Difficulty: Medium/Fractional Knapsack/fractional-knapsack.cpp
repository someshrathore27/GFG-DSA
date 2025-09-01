class Solution {
public:
    struct Item {
        int value, weight;
        double ratio;
    };

    static bool cmp(Item a, Item b) {
        return a.ratio > b.ratio; // sort descending by ratio
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items(n);

        for (int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i], (double)val[i] / wt[i]};
        }

        sort(items.begin(), items.end(), cmp);

        double totalValue = 0.0;
        int curWeight = 0;

        for (int i = 0; i < n; i++) {
            if (curWeight + items[i].weight <= capacity) {
                curWeight += items[i].weight;
                totalValue += items[i].value;
            } else {
                int remain = capacity - curWeight;
                totalValue += items[i].ratio * remain; // fractional part
                break;
            }
        }

        return totalValue;
    }
};
