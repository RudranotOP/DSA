class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalSec= 0;

        for (int i = 0; i < points.size() - 1; i++) {
            int currX = points[i][0];
            int currY = points[i][1];
            
            int nextX = points[i + 1][0];
            int nextY = points[i + 1][1];

            int xDiff = abs(nextX - currX);
            int yDiff = abs(nextY - currY);

            totalSec += max(xDiff, yDiff);
        }

        return totalSec;
    }
};