class Solution {
    int bestHistogramArea(const vector<int>& height) {
        int n = (int)height.size();
        vector<int> st; 
        int best = 0;

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : height[i];

            while (!st.empty() && height[st.back()] > currentHeight) {
                int h = height[st.back()];
                st.pop_back();

                int leftSmallerIndex = st.empty() ? -1 : st.back();
                int width = i - leftSmallerIndex - 1;

                best = max(best, h * width);
            }
            st.push_back(i);
        }
        return best;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = (int)matrix.size();
        if (rows == 0) return 0;
        int cols = (int)matrix[0].size();

        vector<int> height(cols, 0);
        int bestArea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1') height[c] += 1;
                else height[c] = 0;
            }
            bestArea = max(bestArea, bestHistogramArea(height));
        }

        return bestArea;
    }
};