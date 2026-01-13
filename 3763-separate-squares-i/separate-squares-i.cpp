class Solution {
public:
double calculateAreaBelow(const vector<vector<int>>& squares, double yLine) {
        double totalAreaBelow = 0;
        for (const auto& square : squares) {
            double bottom = square[1];
            double side = square[2];
            double top = bottom + side;

            if (yLine > bottom) {
                double heightBelow = min((double)top, yLine) - bottom;
                totalAreaBelow += heightBelow * side;
            }
        }
        return totalAreaBelow;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double minY = 2e9, maxY = -2e9;
        double totalArea = 0;

        for (const auto& square : squares) {
            double y = square[1];
            double side = square[2];
            minY = min(minY, y);
            maxY = max(maxY, y + side);
            totalArea += side * side;
        }

        double low = minY;
        double high = maxY;

        for (int i = 0; i < 100; i++) {
            double midY = low + (high - low) / 2;
            if (calculateAreaBelow(squares, midY) < totalArea / 2.0) {
                low = midY;
            } else {
                high = midY;
            }
        }

        return low;
    }
};