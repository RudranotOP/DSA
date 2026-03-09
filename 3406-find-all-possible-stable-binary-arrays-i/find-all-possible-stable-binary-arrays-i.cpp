class Solution {
public:
static const int MOD = 1000000007;
    int memo[201][201][2];

    int countStableWays(int zerosLeft, int onesLeft, int lastValue, int limit) {
        if (zerosLeft == 0 && onesLeft == 0) {
            return 1;
        }

        if (memo[zerosLeft][onesLeft][lastValue] != -1) {
            return memo[zerosLeft][onesLeft][lastValue];
        }

        long long totalWays = 0;

        if (lastValue == 0) {
            for (int usedOnesNow = 1; usedOnesNow <= min(onesLeft, limit); usedOnesNow++) {
                totalWays += countStableWays(zerosLeft, onesLeft - usedOnesNow, 1, limit);
                totalWays %= MOD;
            }
        } else {
            for (int usedZerosNow = 1; usedZerosNow <= min(zerosLeft, limit); usedZerosNow++) {
                totalWays += countStableWays(zerosLeft - usedZerosNow, onesLeft, 0, limit);
                totalWays %= MOD;
            }
        }

        return memo[zerosLeft][onesLeft][lastValue] = (int)totalWays;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(memo, -1, sizeof(memo));

        long long answer = 0;

        for (int firstZeroBlock = 1; firstZeroBlock <= min(zero, limit); firstZeroBlock++) {
            answer += countStableWays(zero - firstZeroBlock, one, 0, limit);
            answer %= MOD;
        }

        for (int firstOneBlock = 1; firstOneBlock <= min(one, limit); firstOneBlock++) {
            answer += countStableWays(zero, one - firstOneBlock, 1, limit);
            answer %= MOD;
        }

        return (int)answer;
        
    }
};