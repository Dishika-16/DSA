class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        vector<int> freeItems(n, 0);

        // Count free items for each item
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(i != j && items[j][0] % items[i][0] == 0) {
                    freeItems[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for(int i = 0; i < n; i++) {

            int price = items[i][1];
            int gain = 1 + freeItems[i];

            vector<int> temp(budget + 1, -1);

            for(int b = price; b <= budget; b++) {

                // Purchase this item for the first time
                temp[b] = dp[b - price] + gain;

                // Purchase additional copies
                if(temp[b - price] != -1) {
                    temp[b] = max(temp[b],
                                  temp[b - price] + 1);
                }
            }

            for(int b = 0; b <= budget; b++) {
                dp[b] = max(dp[b], temp[b]);
            }
        }

        return dp[budget];
    }
};