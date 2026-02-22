class Solution {
public:
    int binaryGap(int n) {
        int bestGap = 0;
        int previousOnePosition = -1;
        int currentBitPosition = 0;

        while (n > 0) {
            if (n & 1) {
                if (previousOnePosition != -1) {
                    bestGap = max(bestGap, currentBitPosition - previousOnePosition);
                }
                previousOnePosition = currentBitPosition;
            }
            n >>= 1;
            currentBitPosition++;
        }

        return bestGap;
    }
};