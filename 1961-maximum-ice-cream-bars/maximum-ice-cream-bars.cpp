class Solution {
public:

    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 0;
        for (int c : costs) {
            if (c > maxCost) {
             maxCost = c;
            }
        }

        vector<int> count(maxCost + 1, 0);
        for (int c : costs) {
            count[c] += 1;
        }

        int bars = 0;
        for (int i = 1; i <= maxCost; i++) {
            int canBuy = min(count[i], coins / i);
            bars += canBuy;
            coins -= canBuy * i;
        }

    return bars;
    }

};