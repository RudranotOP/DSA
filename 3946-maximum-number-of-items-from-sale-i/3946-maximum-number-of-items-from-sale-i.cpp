class Solution {
public:
int t[1001][1501];

    int solve(int n, int budget, int minPrice, vector<vector<int>>& items, vector<int>& copies) {
        if(n == 0) {
            return budget/minPrice;
        }

        if(t[n][budget] != -1)
            return t[n][budget];

        int take = 0;
        int price = items[n-1][1];

        if(price <= budget) {
            take = 1 + copies[n-1] + solve(n-1, budget-price, minPrice, items, copies);
        }

        int skip = solve(n-1, budget, minPrice, items, copies);

        return t[n][budget] = max(take, skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> copies(n, 0); //copies[i] = count of copies if I buy ith item
        int minPrice = INT_MAX;

        for(int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            int copy = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                if(items[j][0] % items[i][0] == 0)
                    copy++;
            }

            copies[i] = copy;
        }

        memset(t, -1, sizeof(t));
        return solve(n, budget, minPrice, items, copies);
    }
};