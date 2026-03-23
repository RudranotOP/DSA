class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        const long long MOD = 1000000007;

        vector<vector<long long>> largestProduct(totalRows, vector<long long>(totalCols));
        vector<vector<long long>> smallestProduct(totalRows, vector<long long>(totalCols));

        largestProduct[0][0] = grid[0][0];
        smallestProduct[0][0] = grid[0][0];

        for (int row = 1; row < totalRows; row++) {
            largestProduct[row][0] = largestProduct[row - 1][0] * grid[row][0];
            smallestProduct[row][0] = smallestProduct[row - 1][0] * grid[row][0];
        }

        for (int col = 1; col < totalCols; col++) {
            largestProduct[0][col] = largestProduct[0][col - 1] * grid[0][col];
            smallestProduct[0][col] = smallestProduct[0][col - 1] * grid[0][col];
        }

        for (int row = 1; row < totalRows; row++) {
            for (int col = 1; col < totalCols; col++) {
                long long currentValue = grid[row][col];

                long long fromTopMax = largestProduct[row - 1][col] * currentValue;
                long long fromTopMin = smallestProduct[row - 1][col] * currentValue;
                long long fromLeftMax = largestProduct[row][col - 1] * currentValue;
                long long fromLeftMin = smallestProduct[row][col - 1] * currentValue;

                largestProduct[row][col] = max(max(fromTopMax, fromTopMin), max(fromLeftMax, fromLeftMin));
                smallestProduct[row][col] = min(min(fromTopMax, fromTopMin), min(fromLeftMax, fromLeftMin));
            }
        }

        long long finalAnswer = largestProduct[totalRows - 1][totalCols - 1];
        if (finalAnswer < 0) return -1;

        return finalAnswer % MOD;
    }
};