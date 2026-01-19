class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                prefixSum[i][j] = mat[i - 1][j - 1] 
                                + prefixSum[i - 1][j] 
                                + prefixSum[i][j - 1] 
                                - prefixSum[i - 1][j - 1];
            }
        }

        int maxSide = 0;

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int nextSideLength = maxSide + 1;

                if (i >= nextSideLength && j >= nextSideLength) {
                    int currentSquareSum = prefixSum[i][j] 
                                         - prefixSum[i - nextSideLength][j] 
                                         - prefixSum[i][j - nextSideLength] 
                                         + prefixSum[i - nextSideLength][j - nextSideLength];

                    if (currentSquareSum <= threshold) {
                        maxSide++;
                    }
                }
            }
        }

        return maxSide;
    }
};