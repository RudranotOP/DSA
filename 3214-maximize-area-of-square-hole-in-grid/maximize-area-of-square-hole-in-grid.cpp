class Solution {
public:
int calculateMaxGap(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        
        int maxStreak = 1;
        int currentStreak = 1;
        
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                currentStreak++;
            } else {
                currentStreak = 1;
            }
            maxStreak = max(maxStreak, currentStreak);
        }
        
        return maxStreak + 1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxVerticalGap = calculateMaxGap(hBars);
        int maxHorizontalGap = calculateMaxGap(vBars);
        
        int squareSide = min(maxVerticalGap, maxHorizontalGap);
        
        return squareSide * squareSide;
    }
};