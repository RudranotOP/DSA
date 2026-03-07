class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string doubledString = s + s;

        int mismatchWithZeroStart = 0;
        int mismatchWithOneStart = 0;
        int bestAnswer = n;

        int left = 0;

        for (int right = 0; right < doubledString.size(); right++) {
            char expectedForZeroStartAtRight = (right % 2 == 0) ? '0' : '1';
            char expectedForOneStartAtRight  = (right % 2 == 0) ? '1' : '0';

            if (doubledString[right] != expectedForZeroStartAtRight) mismatchWithZeroStart++;
            if (doubledString[right] != expectedForOneStartAtRight)  mismatchWithOneStart++;

            if (right - left + 1 > n) {
                char expectedForZeroStartAtLeft = (left % 2 == 0) ? '0' : '1';
                char expectedForOneStartAtLeft  = (left % 2 == 0) ? '1' : '0';

                if (doubledString[left] != expectedForZeroStartAtLeft) mismatchWithZeroStart--;
                if (doubledString[left] != expectedForOneStartAtLeft)  mismatchWithOneStart--;

                left++;
            }

            if (right - left + 1 == n) {
                bestAnswer = min(bestAnswer, min(mismatchWithZeroStart, mismatchWithOneStart));
            }
        }

        return bestAnswer;
    }
};