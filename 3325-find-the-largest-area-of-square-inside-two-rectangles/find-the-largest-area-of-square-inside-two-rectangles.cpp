class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxSide = 0;
        int n = bottomLeft.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                
                int startX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int startY = max(bottomLeft[i][1], bottomLeft[j][1]);
                
                int endX = min(topRight[i][0], topRight[j][0]);
                int endY = min(topRight[i][1], topRight[j][1]);

                if(startX < endX && startY < endY) {
                    long long width = endX - startX;
                    long long height = endY - startY;
                    
                    long long currentSide = min(width, height);
                    
                    if(currentSide > maxSide) {
                        maxSide = currentSide;
                    }
                }
            }
        }

        return maxSide * maxSide;
    }
};