class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();

        vector<vector<int>> rowPrefixSum(totalRows, vector<int>(totalCols + 1, 0));
        vector<vector<int>> colPrefixSum(totalRows + 1, vector<int>(totalCols, 0));

        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalCols; ++j) {
                rowPrefixSum[i][j + 1] = rowPrefixSum[i][j] + grid[i][j];
                colPrefixSum[i + 1][j] = colPrefixSum[i][j] + grid[i][j];
            }
        }

        int maxPossibleSize = min(totalRows, totalCols);

        for (int size = maxPossibleSize; size > 1; --size) {
            for (int row = 0; row <= totalRows - size; ++row) {
                for (int col = 0; col <= totalCols - size; ++col) {
                    
                    int targetSum = rowPrefixSum[row][col + size] - rowPrefixSum[row][col];
                    bool isValid = true;

                    for (int k = 0; k < size; ++k) {
                        int currentRowSum = rowPrefixSum[row + k][col + size] - rowPrefixSum[row + k][col];
                        int currentColSum = colPrefixSum[row + size][col + k] - colPrefixSum[row][col + k];

                        if (currentRowSum != targetSum || currentColSum != targetSum) {
                            isValid = false;
                            break;
                        }
                    }

                    if (!isValid) continue;

                    int diagonalSum = 0;
                    int antiDiagonalSum = 0;

                    for (int k = 0; k < size; ++k) {
                        diagonalSum += grid[row + k][col + k];
                        antiDiagonalSum += grid[row + k][col + size - 1 - k];
                    }

                    if (diagonalSum == targetSum && antiDiagonalSum == targetSum) {
                        return size;
                    }
                }
            }
        }

        return 1;
    
    }
};